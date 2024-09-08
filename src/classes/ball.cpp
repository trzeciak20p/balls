#include "ball.h"
#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Window.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <numbers>

using std::numbers::pi;

Ball::Ball(float _x, float _y, float _size, sf::Color _color)
    : x{_x + _size}, y{_y + _size}, color{_color}
{
    body.setPosition(x, y);
    body.setRadius(_size);
    body.setFillColor(_color);
    body.setOrigin(sf::Vector2f(_size, _size));
    balls.push_back(*this);
}

// Ball::~Ball() = default;
// make some exsplosion effect

void Ball::initialize(sf::Window *_window)
{
    Ball::window       = _window;
    Ball::board_width  = window->getSize().x;
    Ball::board_height = window->getSize().y;
    Ball::friction     = 0.9;
}

sf::Vector2f Ball::getPos() const
{
    return {x, y};
}

float Ball::getDistacne(float _x, float _y) const
{
    return std::sqrt((_x - x) * (_x - x) + (_y - y) * (_y - y));
}

void Ball::checkBounce()
{
    for (auto &wall : walls)
    {
        const float new_x = x + vel_x;
        const float new_y = y + vel_y;
        float       angle = NAN;
        angle             = bnw::getEquationAngle(getPos(), sf::Vector2f(new_x, new_y));

        // Cheking for corners
        if (const auto distance =
                static_cast<float>(getDistacne(wall.getLeft() - vel_x, wall.getTop() - vel_y) <= body.getRadius()))
        {
            if (angle < 0)
            {
                if (x > y)
                { // Determining which side is ball comming from
                    // right
                    x = wall.getLeft() + cos(pi + pi / 4 + angle) * (distance * 10 + body.getRadius());
                    y = wall.getTop() - sin(pi + pi / 4 + angle) * (distance * 10 + body.getRadius());
                }
                else
                {
                    // left
                    x = wall.getLeft() + cos(angle - pi / 4) * (distance * 10 + body.getRadius());
                    y = wall.getTop() - sin(angle - pi / 4) * (distance * 10 + body.getRadius());
                }
            }
            else
            {
                x                        = wall.getLeft() + cos(pi / 2 + angle) * (distance * 10 + body.getRadius());
                y                        = wall.getTop() - sin(pi / 2 + angle) * (distance * 10 + body.getRadius());
                const float vel_x_buffer = vel_x;
                vel_x                    = -vel_y;
                vel_y                    = -vel_x_buffer;
                decrease_vel_x *= -1;
                decrease_vel_y *= -1;
            }

            std::cout << "diff x: " << x - wall.getLeft() << "diff y: " << y - wall.getTop() << "\n";
        }
        else if (getDistacne(wall.getLeft() - vel_x, wall.getBottom() - vel_y) <= body.getRadius())
        {
        }
        else if (getDistacne(wall.getRight() - vel_x, wall.getTop() - vel_y) <= body.getRadius())
        {
        }
        else if (getDistacne(wall.getRight() - vel_x, wall.getBottom() - vel_y) <= body.getRadius())
        {
        }
        else
        {
            // Checking for sides
            if ((new_x + body.getRadius() > wall.getLeft() || new_x - body.getRadius() > wall.getRight()) &&
                (new_y >= wall.getTop() && new_y <= wall.getBottom()))
            {
                vel_x *= -1;
                decrease_vel_x *= -1;
            }
            if ((new_y + body.getRadius() > wall.getTop() || new_y - body.getRadius() > wall.getBottom()) &&
                (new_x >= wall.getLeft() && new_x <= wall.getRight()))
            {
                vel_y *= -1;
                decrease_vel_y *= -1;
            }
            return;
        }

        std::cout << "angle: " << std::atan(angle) << "\n";
    }

    // TODO(abfipes): uwzględnić prędkość obu piłek
}

bool Ball::checkHover(float x, float y)
{ // Checks if cursor hovers over ball
    if (getDistacne(x, y) <= body.getRadius())
    {
        Ball::active_ball = this;
        return true;
    }
    return false;
}

void Ball::setSpeed(float x, float y)
{
    if (movable)
    {
        movable        = false;
        vel_x          = x / 2;
        vel_y          = y / 2;
        decrease_vel_x = x / Ball::friction;
        decrease_vel_y = y / Ball::friction;
    }
}

void Ball::update()
{
    if (vel_x == 0.0 && vel_y == 0.0)
    {
        return;
    }

    if (x + vel_x < body.getRadius() || x + vel_x >= Ball::board_width - body.getRadius())
    { // changing directions from boundaries
        vel_x *= -1;
        decrease_vel_x *= -1;
    }
    if (y + vel_y < body.getRadius() || y + vel_y >= Ball::board_height - body.getRadius())
    {
        vel_y *= -1;
        decrease_vel_y *= -1;
    }

    checkBounce();

    x += vel_x;
    y += vel_y;

    body.setPosition(sf::Vector2f(x, y));

    vel_x *= Ball::friction; // lowering speed
    vel_y *= Ball::friction;

    if (std::abs(vel_x) < 0.2 && std::abs(vel_y) < 0.2)
    {
        vel_x = vel_y = 0;
        Ball::movable = true;
    }
}