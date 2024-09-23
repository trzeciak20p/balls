#include "game.h"
#include "gui/gui.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>
#include <iostream>
#include <numbers>

constexpr float pi{std::numbers::pi_v<float>};

Game::Game(sf::RenderWindow* window)
    : m_window{window}
{
    m_view.reset(sf::FloatRect(0, 0, 800, 700));
    m_window->setView(m_view);
    m_ui = UI();
    m_ui.loadGuiScenario(GUI::Scenario::menu);
    m_ui.loadGuiScenario(GUI::Scenario::options);
}

void Game::setLastClick()
{
    m_last_click = getMouse();
}

Vec2f Game::getMouse()
{
    // get the current mouse position in the window
    const sf::Vector2i pixel_pos = sf::Mouse::getPosition(*m_window);

    // convert it to world coordinates
    return m_window->mapPixelToCoords(pixel_pos);
}

void Game::mousePress()
{
    setLastClick();
    m_ui.mousePress(m_last_click);
    board.mousePress(m_last_click);
}

void Game::mouseRelease()
{
    m_ui.mouseRelease();
    board.mouseRelease(getMouse(), m_last_click);
}

void Game::eventHandle(sf::Event event)
{
    switch (event.type)
    {
    case sf::Event::Closed:
        m_window->close();
        break;

    case sf::Event::MouseButtonPressed:
        mousePress();
        break;

    case sf::Event::MouseButtonReleased:
        mouseRelease();
        break;

    case sf::Event::KeyPressed:
        std::cerr << "kpress: " << sf::Keyboard::getDescription(event.key.scancode).toAnsiString() << '\n';
        m_view.move(0, 10);
        m_window->setView(m_view);
        break;

    case sf::Event::KeyReleased:

    default:
        break;
    }
}

void Game::update()
{
    m_ui.update(getMouse());
    board.update(m_last_click, getMouse());
}

void Game::draw()
{
    m_ui.draw(m_window);
    board.draw(m_window);
}