#include "game.h"
#include "fontLoader.h"
#include "gui/gui_menu.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cmath>
#include <memory>
#include <numbers>
#include <utility>

constexpr float pi{std::numbers::pi_v<float>};

Game::Game()
{
    bnw::loadFont("fonts/comic.ttf");

    m_window.create(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);
    m_window.setFramerateLimit(60);

    m_view.reset(sf::FloatRect(0, 0, 800, 700));
    m_window.setView(m_view);

    m_ui.loadGuiScenario(std::make_unique<gui::GuiMenu>(*this));
    m_ui.loadGuiScenario(std::make_unique<gui::GuiOptions>(m_board.get()));
}

void Game::gaming()
{
    while (m_window.isOpen())
    {
        sf::Event event{};
        while (m_window.pollEvent(event))
        {
            eventHandle(event);
        }

        update();
        draw();
    }
}

void Game::loadBoard()
{
    m_board = std::make_unique<Board>("maps/map1");
}

void Game::setLastClick()
{
    m_last_click = getMouse();
}

Vec2f Game::getMouse()
{
    const sf::Vector2i pixel_pos = sf::Mouse::getPosition(m_window);

    return m_window.mapPixelToCoords(pixel_pos);
}

void Game::mousePress()
{
    setLastClick();
    m_ui.mousePress(m_last_click);

    if (m_board)
    {
        m_board->mousePress(m_last_click);
    }
}

void Game::mouseRelease()
{
    m_ui.mouseRelease();

    if (m_board)
    {
        m_board->mouseRelease(getMouse(), m_last_click);
    }
}

void Game::keyPress()
{
    // std::cerr << "kpress: " << sf::Keyboard::getDescription(event.key.scancode).toAnsiString() << '\n';
    m_view.move(0, 10);
    m_window.setView(m_view);
}

void Game::eventHandle(sf::Event event)
{
    switch (event.type)
    {
    case sf::Event::Closed:
        m_window.close();
        break;

    case sf::Event::MouseButtonPressed:
        mousePress();
        break;

    case sf::Event::MouseButtonReleased:
        mouseRelease();
        break;

    case sf::Event::KeyPressed:
        keyPress();

        break;

    case sf::Event::KeyReleased:

    default:
        break;
    }
}

void loadBoard()
{
}

void Game::update()
{
    m_ui.update(getMouse());

    if (!m_board)
    {
        return;
    }
    m_board->update(m_last_click, getMouse());
}

void Game::draw()
{
    m_window.clear({102, 102, 102});

    m_ui.draw(m_window);

    if (m_board)
    {
        m_board->draw(m_window);
    }

    m_window.display();
}