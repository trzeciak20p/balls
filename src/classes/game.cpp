#include "game.h"
#include "ball.h"
#include "button.h"
#include "slider.h"
#include "utils_2d.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <cmath>
#include <iostream>
#include <numbers>

constexpr float pi{std::numbers::pi_v<float>};

Game::Game(sf::Window *window)
    : m_window{window}
{
}

Game::State Game::getState()
{
    return m_state;
}

bool Game::calculateTrail()
{
    if (!m_dragging)
    {
        return false;
    }
    const float distance = bnw::getDistacne(sf::Vector2f(m_mouse), sf::Vector2f(sf::Mouse::getPosition(*m_window)));
    const float angle    = bnw::getAngle(sf::Vector2f(sf::Mouse::getPosition(*m_window) - m_mouse));
    const float x        = std::cos(angle + pi / 2) * m_active_ball->getRadius() / 2;
    const float y        = std::sin(angle + pi / 2) * m_active_ball->getRadius() / 2;

    if (distance < 200)
    {
        const sf::Color trail_color((distance <= 100) ? (distance / 100 * 255) : (255),
                                    (distance >= 100) ? ((100 - distance) / 100 * 255) : (255), 0);

        m_trail[0] = {m_active_ball->getPosition() + sf::Vector2f(x, y), trail_color};
        m_trail[1] = {m_active_ball->getPosition() - sf::Vector2f(x, y), trail_color};
        m_trail[2] = {m_active_ball->getPosition() * 2.0F - sf::Vector2f(sf::Mouse::getPosition(*m_window)),
                      trail_color};

        m_active_ball->setFillColor(trail_color);
    }
    else
    {
        // speed velocity cap
        m_trail[0] = {m_active_ball->getPosition() + sf::Vector2f(x, y), sf::Color::Red};
        m_trail[1] = {m_active_ball->getPosition() - sf::Vector2f(x, y), sf::Color::Red};

        const float tip_x = std::cos(angle) * 200;
        const float tip_y = std::sin(angle) * 200;

        if (sf::Mouse::getPosition(*m_window).x < m_active_ball->getPosition().x + 2.5F)
        {
            m_trail[2] = {m_active_ball->getPosition() + sf::Vector2f(tip_x, tip_y), sf::Color::Red};
        }
        else
        {
            m_trail[2] = {m_active_ball->getPosition() - sf::Vector2f(tip_x, tip_y), sf::Color::Red};
        }
        m_active_ball->setFillColor(sf::Color::Red);
    }
    return true;
}

void Game::updateMouse()
{
    m_mouse = sf::Mouse::getPosition(*m_window);
}

void Game::mousePress()
{
    switch (m_state)
    {
    case menu:
        for (auto &button : buttons)
        {
            if (button.checkHover(m_mouse))
            {
                button.onUse();
            }
        }
        for (auto &slider : sliders)
        {
            if (slider.checkHover(m_mouse))
            {
                slider.setActive();
            }
        }
        break;
    case map_selection:
    case settings:

        break;

    case playing:
        for (auto &i : to_board->m_balls)
        { // checking if hovered over ball
            if (!i.checkHover(sf::Vector2f(m_mouse)))
            {
                continue;
            }
            m_active_ball = &i;
            m_dragging    = true;
            break;
        }
        break;

    default:
        std::cerr << "MOSUE CLICK SWITCH ERROR\n";
        break;
    }
}

const sf::VertexArray &Game::getTrial()
{
    return m_trail;
}

void Game::mouseRelease()
{
    switch (m_state)
    {
    case menu:
        Slider::clearActive();
        break;
    case map_selection:
    case settings:

        break;

    case playing:
        if (!m_dragging)
        {
            break;
        }

        m_active_ball->setSpeed(sf::Vector2f(m_mouse - sf::Mouse::getPosition(*m_window)) / 6.0F);
        m_active_ball->setFillColor(m_active_ball->m_color);
        m_dragging = false;
        break;

    default:
        std::cerr << "MOSUE CLICK SWITCH ERROR\n";
        break;
    }
}