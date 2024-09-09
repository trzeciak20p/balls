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

Ball::Ball(float x, float y, float radius, sf::Color color, Board* board)
    : m_x{x + radius}, m_y{y + radius}, m_color{color}, m_board {board}
{
    body.setPosition(m_x, m_y);
    body.setRadius(radius);
    body.setFillColor(color);
    body.setOrigin(sf::Vector2f(radius, radius));
}

// Ball::~Ball() = default;
// make some exsplosion effect

sf::Vector2f Ball::getPos() const
{
    return {m_x, m_y};
}

float Ball::getDistacne(float x, float y) const
{
    return std::sqrt((x - m_x) * (x - m_x) + (y - m_y) * (y - m_y));
}

void Ball::checkBounce()
{
    for (auto &wall : m_board->m_walls)
    {
        const float new_x = m_x + m_vel_x;
        const float new_y = m_y + m_vel_y;
        float       angle = bnw::getEquationAngle(getPos(), sf::Vector2f(new_x, new_y));

        // Cheking for corners
        if (const auto distance =
                static_cast<float>(getDistacne(wall.getLeft() - m_vel_x, wall.getTop() - m_vel_y) <= body.getRadius()))
        {
            if (angle < 0)
            {
                if (m_x > m_y)
                { // Determining which side is ball comming from
                    // right
                    m_x = wall.getLeft() + cos(pi + pi / 4 + angle) * (distance * 10 + body.getRadius());
                    m_y = wall.getTop() - sin(pi + pi / 4 + angle) * (distance * 10 + body.getRadius());
                }
                else
                {
                    // left
                    m_x = wall.getLeft() + cos(angle - pi / 4) * (distance * 10 + body.getRadius());
                    m_y = wall.getTop() - sin(angle - pi / 4) * (distance * 10 + body.getRadius());
                }
            }
            else
            {
                m_x                        = wall.getLeft() + cos(pi / 2 + angle) * (distance * 10 + body.getRadius());
                m_y                        = wall.getTop() - sin(pi / 2 + angle) * (distance * 10 + body.getRadius());
                const float vel_x_buffer = m_vel_x;
                m_vel_x                    = -m_vel_y;
                m_vel_y                    = -vel_x_buffer;
                m_decrease_vel_x *= -1;
                m_decrease_vel_y *= -1;
            }

            std::cout << "diff x: " << m_x - wall.getLeft() << "diff y: " << m_y - wall.getTop() << "\n";
        }
        else if (getDistacne(wall.getLeft() - m_vel_x, wall.getBottom() - m_vel_y) <= body.getRadius())
        {
        }
        else if (getDistacne(wall.getRight() - m_vel_x, wall.getTop() - m_vel_y) <= body.getRadius())
        {
        }
        else if (getDistacne(wall.getRight() - m_vel_x, wall.getBottom() - m_vel_y) <= body.getRadius())
        {
        }
        else
        {
            // Checking for sides
            if ((new_x + body.getRadius() > wall.getLeft() || new_x - body.getRadius() > wall.getRight()) &&
                (new_y >= wall.getTop() && new_y <= wall.getBottom()))
            {
                m_vel_x *= -1;
                m_decrease_vel_x *= -1;
            }
            if ((new_y + body.getRadius() > wall.getTop() || new_y - body.getRadius() > wall.getBottom()) &&
                (new_x >= wall.getLeft() && new_x <= wall.getRight()))
            {
                m_vel_y *= -1;
                m_decrease_vel_y *= -1;
            }
            return;
        }

        std::cout << "angle: " << std::atan(angle) << "\n";
    }

    // TODO(abfipes): uwzględnić prędkość obu piłek
}

bool Ball::checkHover(float x, float y)
{ // Checks if cursor hovers over ball
    return getDistacne(x, y) <= body.getRadius();
}

void Ball::setSpeed(float x, float y)
{
    if (m_board->m_balls_movable)
    {
        m_board->m_balls_movable = false;
        m_vel_x                    = x / 2;
        m_vel_y                    = y / 2;
        m_decrease_vel_x           = x / m_friction;
        m_decrease_vel_y           = y / m_friction;
    }
}

void Ball::update()
{
    if (m_vel_x == 0.0 && m_vel_y == 0.0)
    {
        return;
    }

    if (m_x + m_vel_x < body.getRadius() || m_x + m_vel_x >= m_board->m_width - body.getRadius())
    { // changing directions from boundaries
        m_vel_x *= -1;
        m_decrease_vel_x *= -1;
    }
    if (m_y + m_vel_y < body.getRadius() || m_y + m_vel_y >= m_board->m_height - body.getRadius())
    {
        m_vel_y *= -1;
        m_decrease_vel_y *= -1;
    }

    checkBounce();

    m_x += m_vel_x;
    m_y += m_vel_y;

    body.setPosition(sf::Vector2f(m_x, m_y));

    m_vel_x *= m_friction; // lowering speed
    m_vel_y *= m_friction;

    if (std::abs(m_vel_x) < 0.2 && std::abs(m_vel_y) < 0.2)
    {
        m_vel_x = m_vel_y            = 0;
        m_board->m_balls_movable = true;
    }
}