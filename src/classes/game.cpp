#include "game.h"
#include "ball.h"
#include "utils_2d.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <cmath>
#include <iostream>
#include <numbers>

using std::numbers::pi;

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
    if (!dragging)
    {
        return false;
    }
    const float distance = bnw::getDistacne(sf::Vector2f(mouse), sf::Vector2f(sf::Mouse::getPosition(*m_window)));
    const float angle    = bnw::getEquationAngle(sf::Vector2f(sf::Mouse::getPosition(*m_window) - mouse));
    const float x        = std::cos(angle + pi / 2) * active_ball->getRadius() / 2;
    const float y        = std::sin(angle + pi / 2) * active_ball->getRadius() / 2;

    if (distance < 200)
    {
        const sf::Color trail_color((distance <= 100) ? (distance / 100 * 255) : (255),
                                    (distance >= 100) ? ((100 - distance) / 100 * 255) : (255), 0);

        trail[0] = sf::Vertex(active_ball->getPosition() + sf::Vector2f(x, y), trail_color);
        trail[1] = sf::Vertex(active_ball->getPosition() - sf::Vector2f(x, y), trail_color);
        trail[2] = sf::Vertex(active_ball->getPosition() * 2.0F - sf::Vector2f(sf::Mouse::getPosition(*m_window)),
                              trail_color);

        active_ball->setFillColor(trail_color);
    }
    else
    { // speed velocity cap
        trail[0]          = sf::Vertex(active_ball->getPosition() + sf::Vector2f(x, y), sf::Color::Red);
        trail[1]          = sf::Vertex(active_ball->getPosition() - sf::Vector2f(x, y), sf::Color::Red);
        const float tip_x = std::cos(angle) * 200;
        const float tip_y = std::sin(angle) * 200;

        std::cout << sf::Mouse::getPosition(*m_window).x << " " << active_ball->getPosition().x << " " << angle
                  << " \n";

        if (sf::Mouse::getPosition(*m_window).x < active_ball->getPosition().x + 2.5)
        {
            trail[2] = sf::Vertex(active_ball->getPosition() + sf::Vector2f(tip_x, tip_y), sf::Color::Red);
        }
        else
        {
            trail[2] = sf::Vertex(active_ball->getPosition() - sf::Vector2f(tip_x, tip_y), sf::Color::Red);
        }
        active_ball->setFillColor(sf::Color::Red);
    }
    return true;
}

void Game::mousePress()
{
    switch (m_state)
    {
    case Game::State::menu:
    case Game::State::map_selection:
    case Game::State::settings:
    case Game::State::paused:
        break;

    case Game::State::playing:
        mouse = sf::Mouse::getPosition(*m_window);
        for (auto &i : to_board->m_balls)
        {
            // checking if hovered over ball
            if (!i.checkHover(sf::Vector2f(mouse)))
            {
                continue;
            }
            active_ball = &i;
            dragging    = true;
            break;
        }
        break;

    default:
        std::cerr << "MOSUE CLICK SWITCH ERROR\n";
        break;
    }
}

void Game::mouseRelease()
{
    switch (m_state)
    {
    case Game::State::menu:
    case Game::State::map_selection:
    case Game::State::settings:
    case Game::State::paused:
        break;

    case Game::State::playing:
        if (!dragging)
        {
            break;
        }

        active_ball->setSpeed(sf::Vector2f(mouse - sf::Mouse::getPosition(*m_window)) / 6.0F);
        active_ball->setFillColor(active_ball->m_color);
        dragging = false;
        break;

    default:
        std::cerr << "MOSUE CLICK SWITCH ERROR\n";
        break;
    }
}