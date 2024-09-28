#include "game.h"
#include "vec2f.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cmath>
#include <numbers>

constexpr float pi{std::numbers::pi_v<float>};

Game::Game()
{
    m_window.create(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close | sf::Style::Resize);
    m_window.setFramerateLimit(60);
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
    m_gui.mousePress(getMouse());

    m_simulation.mousePress(m_window, getMouse());
}

void Game::mouseRelease()
{
    m_gui.mouseRelease();

    m_simulation.mouseRelease(m_window, getMouse());
}

void Game::keyPress(sf::Event::KeyEvent key)
{
    // złe narazie (+ nie działa)
    switch (key.scancode)
    {
    case sf::Keyboard::Scan::Scancode::Right:
        m_simulation.moveView({10.F, 0.F});
        break;
    case sf::Keyboard::Scan::Scancode::Left:
        m_simulation.moveView({-10.F, 0.F});
        break;
    case sf::Keyboard::Scan::Scancode::Up:
        m_simulation.moveView({0.F, -10.F});
        break;
    case sf::Keyboard::Scan::Scancode::Down:
        m_simulation.moveView({0.F, 10.F});
        break;

    default:
        break;
    }
}

void Game::onResize(sf::Event::SizeEvent size)
{
    const sf::FloatRect visible_area(0.F, 0.F, size.width, size.height);
    m_window.setView(sf::View(visible_area));

    m_simulation.onResize(size);
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
        keyPress(event.key);
        break;

    case sf::Event::KeyReleased:

        break;

    case sf::Event::Resized:
        onResize(event.size);
        break;

    default:
        break;
    }
}

sim::Simulation& Game::getSimulation()
{
    return m_simulation;
}

void Game::update()
{
    m_gui.update(getMouse());

    m_simulation.update(m_window, getMouse());
}

void Game::draw()
{
    m_window.clear({102, 102, 102});

    m_simulation.draw(m_window);

    m_gui.draw(m_window);

    m_window.display();
}