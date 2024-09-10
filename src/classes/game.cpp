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
#include <string>

using std::numbers::pi;

Game::Game(sf::Window *window)
    : m_window{window}
{
}

Game::State Game::getState()
{
    return m_state;
}

void Game::errorReport(const std::string &err)
{
    std::cout << err << "\n";
}

bool Game::calculateTrail()
{
    if (!dragging)
    {
        return false;
    }
    const float distance = sqrt(pow(mouse.x - sf::Mouse::getPosition(*m_window).x, 2) +
                                pow(mouse.y - sf::Mouse::getPosition(*m_window).y, 2));
    const float angle    = bnw::getEquationAngle(sf::Vector2f(mouse), sf::Vector2f(sf::Mouse::getPosition(*m_window)));
    const float x        = cos(angle + pi / 2) * to_board->active_ball->body.getRadius() / 2;
    const float y        = sin(angle + pi / 2) * to_board->active_ball->body.getRadius() / 2;

    if (distance < 200)
    {
        const sf::Color trail_color((distance <= 100) ? (distance / 100 * 255) : (255),
                                    (distance >= 100) ? ((100 - distance) / 100 * 255) : (255), 0);

        trail[0] = sf::Vertex(
            sf::Vector2f(to_board->active_ball->getPos().x + x, to_board->active_ball->getPos().y + y), trail_color);
        trail[1] = sf::Vertex(
            sf::Vector2f(to_board->active_ball->getPos().x - x, to_board->active_ball->getPos().y - y), trail_color);
        trail[2] = sf::Vertex(
            sf::Vector2f(2 * sf::Vector2i(to_board->active_ball->getPos()) - sf::Mouse::getPosition(*m_window)),
            trail_color);

        to_board->active_ball->body.setFillColor(trail_color);
    }
    else
    { // speed velocity cap
        trail[0] = sf::Vertex(
            sf::Vector2f(to_board->active_ball->getPos().x + x, to_board->active_ball->getPos().y + y), sf::Color::Red);
        trail[1] = sf::Vertex(
            sf::Vector2f(to_board->active_ball->getPos().x - x, to_board->active_ball->getPos().y - y), sf::Color::Red);
        const float tip_x = std::cos(angle) * 200;
        const float tip_y = std::sin(angle) * 200;

        std::cout << sf::Mouse::getPosition(*m_window).x << " " << to_board->active_ball->getPos().x << " " << angle
                  << " \n";

        if (sf::Mouse::getPosition(*m_window).x < to_board->active_ball->getPos().x + 2.5)
        {
            trail[2] = sf::Vertex(
                sf::Vector2f(to_board->active_ball->getPos().x + tip_x, to_board->active_ball->getPos().y + tip_y),
                sf::Color::Red);
        }
        else
        {
            trail[2] = sf::Vertex(
                sf::Vector2f(to_board->active_ball->getPos().x - tip_x, to_board->active_ball->getPos().y - tip_y),
                sf::Color::Red);
        }
        to_board->active_ball->body.setFillColor(sf::Color::Red);
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
        { // checking if hovered over ball
            if (i.checkHover(mouse.x, mouse.y))
            {
                to_board->active_ball = &i;
                dragging              = true;
                break;
            }
        }
        break;

    default:
        errorReport("MOSUE CLICK SWITCH ERROR");
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
        if (dragging)
        {
            to_board->active_ball->setSpeed((mouse.x - sf::Mouse::getPosition(*m_window).x) / 3,
                                            (mouse.y - sf::Mouse::getPosition(*m_window).y) / 3);
            to_board->active_ball->body.setFillColor(to_board->active_ball->m_color);
            dragging = false;
        }
        break;

    default:
        errorReport("MOSUE CLICK SWITCH ERROR");
        break;
    }
}