#include "game.h"
#include "board/board.h"
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

constexpr float pi{std::numbers::pi_v<float>};

Game::Game()
{
    bnw::loadFont("fonts/comic.ttf");

    m_window.create(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);
    m_window.setFramerateLimit(60);

    m_ui.loadGuiScenario(std::make_unique<gui::GuiMenu>(this));
    // m_ui.loadGuiScenario(std::make_unique<gui::GuiOptions>(m_board.get()));
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

Vec2f Game::getMouse()
{
    return static_cast<Vec2f>(sf::Mouse::getPosition(m_window));
}

void Game::mousePress()
{
    m_ui.mousePress(getMouse());

    m_simulation.mousePress(m_window, getMouse());
}

void Game::mouseRelease()
{
    m_ui.mouseRelease();

    m_simulation.mouseRelease(m_window, getMouse());
}

void Game::keyPress()
{
    // std::cerr << "kpress: " << sf::Keyboard::getDescription(event.key.scancode).toAnsiString() << '\n';
    // m_view.move(0, 10);
    // m_window.setView(m_view);
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

    m_simulation.update(m_window, getMouse());
}

void Game::draw()
{
    m_window.clear({102, 102, 102});

    m_simulation.draw(m_window);

    m_ui.draw(m_window);

    m_window.display();
}