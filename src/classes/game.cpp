#include "game.h"
#include "ball.h"
#include "slider.h"
#include "utils_2d.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
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
    m_ui.loadGuiScenario("a");
}

void Game::drawTrail()
{
    if (!m_dragging || m_active_ball == nullptr)
    {
        return;
    }
    sf::VertexArray trail{sf::Triangles, 3};
    const float     distance = bnw::getDistacne(m_last_click, getMouse());
    const float     angle    = bnw::getAngle(getMouse() - m_last_click);
    const float     x        = std::cos(angle + pi / 2) * m_active_ball->getRadius() / 2;
    const float     y        = std::sin(angle + pi / 2) * m_active_ball->getRadius() / 2;

    if (distance < 200)
    {
        const sf::Color trail_color((distance <= 100) ? (distance / 100 * 255) : (255),
                                    (distance >= 100) ? ((100 - distance) / 100 * 255) : (255), 0);
        trail[0] = {m_active_ball->getPosition() + sf::Vector2f(x, y), trail_color};
        trail[1] = {m_active_ball->getPosition() - sf::Vector2f(x, y), trail_color};
        trail[2] = {m_active_ball->getPosition() * 2.0F - getMouse(), trail_color};

        m_active_ball->setFillColor(trail_color);
    }
    else
    {
        // speed velocity cap
        trail[0] = {m_active_ball->getPosition() + sf::Vector2f(x, y), sf::Color::Red};
        trail[1] = {m_active_ball->getPosition() - sf::Vector2f(x, y), sf::Color::Red};

        const float tip_x = std::cos(angle) * 200;
        const float tip_y = std::sin(angle) * 200;

        if (getMouse().x < m_active_ball->getPosition().x + 2.5F)
        {
            trail[2] = {m_active_ball->getPosition() + sf::Vector2f(tip_x, tip_y), sf::Color::Red};
        }
        else
        {
            trail[2] = {m_active_ball->getPosition() - sf::Vector2f(tip_x, tip_y), sf::Color::Red};
        }
        m_active_ball->setFillColor(sf::Color::Red);
    }
    m_window->draw(trail);
}

void Game::setLastClick()
{
    m_last_click = getMouse();
}

sf::Vector2f Game::getMouse()
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

    for (auto& ball : board.m_balls)
    {
        if (!ball.checkHover(m_last_click))
        {
            continue;
        }
        m_active_ball = &ball;
        break;
    }
    m_dragging = true;
}

void Game::mouseRelease()
{
    Slider::clearActive();

    if (!m_dragging)
    {
        return;
    }
    m_dragging = false;
    if (m_active_ball == nullptr)
    {
        return;
    }

    m_active_ball->setSpeed((m_last_click - getMouse()) / 6.0F);
    m_active_ball->setFillColor(m_active_ball->m_color);
    m_active_ball = nullptr;
}

void Game::eventHandle(sf::Event event)
{
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
}

void Game::update()
{
    m_ui.update(getMouse());
    board.update();
}

void Game::draw()
{
    m_ui.draw(m_window);
    board.draw(m_window);
    drawTrail();
}