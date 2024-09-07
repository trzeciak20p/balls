#include "game.h"
#include "ball.h"
#include "button.h"
#include "utils_2d.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <cmath>
#include <iostream>
#include <string>

Game::Game(sf::Window *_window) : window{_window}, state(State::menu)
{
}

Game::State Game::getState()
{
    return state;
}

void Game::errorReport(const std::string &err)
{
    std::cout << err << "\r\n";
}

bool Game::calculateTrail()
{
    if (!(dragging && Ball::movable))
    {
        return false;
    }
    float const distance =
        sqrt(pow(mouse.x - sf::Mouse::getPosition(*window).x, 2) + pow(mouse.y - sf::Mouse::getPosition(*window).y, 2));
    float const angle = bnw::getEquationAngle((sf::Vector2f)mouse, (sf::Vector2f)sf::Mouse::getPosition(*window));
    float const x = cos(angle + M_PI_2) * Ball::active_ball->body.getRadius() / 2;
    float const y = sin(angle + M_PI_2) * Ball::active_ball->body.getRadius() / 2;

    if (distance < 200)
    {
        sf::Color const trail_color((distance <= 100) ? (distance / 100 * 255) : (255),
                                    (distance >= 100) ? ((100 - distance) / 100 * 255) : (255), 0);

        trail[0] =
            sf::Vertex(sf::Vector2f(Ball::active_ball->getPos().x + x, Ball::active_ball->getPos().y + y), trail_color);
        trail[1] =
            sf::Vertex(sf::Vector2f(Ball::active_ball->getPos().x - x, Ball::active_ball->getPos().y - y), trail_color);
        trail[2] = sf::Vertex(
            sf::Vector2f(2 * (sf::Vector2i)Ball::active_ball->getPos() - sf::Mouse::getPosition(*window)), trail_color);

        Ball::active_ball->body.setFillColor(trail_color);
    }
    else
    { // speed velocity cap
        trail[0] = sf::Vertex(sf::Vector2f(Ball::active_ball->getPos().x + x, Ball::active_ball->getPos().y + y),
                              sf::Color::Red);
        trail[1] = sf::Vertex(sf::Vector2f(Ball::active_ball->getPos().x - x, Ball::active_ball->getPos().y - y),
                              sf::Color::Red);
        float const tip_x = cos(angle) * 200;
        float const tip_y = sin(angle) * 200;

        std::cout << sf::Mouse::getPosition(*window).x << " " << Ball::active_ball->getPos().x << " " << angle
                  << " \r\n";

        if (sf::Mouse::getPosition(*window).x < Ball::active_ball->getPos().x + 2.5)
        {
            trail[2] =
                sf::Vertex(sf::Vector2f(Ball::active_ball->getPos().x + tip_x, Ball::active_ball->getPos().y + tip_y),
                           sf::Color::Red);
        }
        else
        {
            trail[2] =
                sf::Vertex(sf::Vector2f(Ball::active_ball->getPos().x - tip_x, Ball::active_ball->getPos().y - tip_y),
                           sf::Color::Red);
        }
        Ball::active_ball->body.setFillColor(sf::Color::Red);
    }
    return true;
}

void Game::mousePress()
{
    mouse = sf::Mouse::getPosition(*window);
    switch (state)
    {
    case Game::State::menu:
        for (auto &i : buttons)
        {
            if (i.checkHover(mouse))
            {
                i.onClick();
            }
        }
        break;
    case Game::State::map_selection:
    case Game::State::settings:

        break;

    case Game::State::playing:
        for (auto &i : balls)
        { // checking if hovered over ball
            if (i.checkHover(mouse.x, mouse.y))
            {
                dragging = true;
                break;
            }
        }

        break;
    case Game::State::paused:

        break;
    default:
        errorReport("MOSUE CLICK SWITCH ERROR");
        break;
    }
}

void Game::mouseRelease()
{
    switch (state)
    {
    case Game::State::menu:
    case Game::State::map_selection:
    case Game::State::settings:

        break;

    case Game::State::playing:
        if (dragging)
        {
            Ball::active_ball->setSpeed((mouse.x - sf::Mouse::getPosition(*window).x) / 3,
                                        (mouse.y - sf::Mouse::getPosition(*window).y) / 3);
            Ball::active_ball->body.setFillColor(Ball::active_ball->color);
            dragging = false;
        }
        break;
    case Game::State::paused:

        break;
    default:
        errorReport("MOSUE CLICK SWITCH ERROR");
        break;
    }
}