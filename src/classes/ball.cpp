#include "ball.h"
#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include <cstdlib>
#include <numbers>
#include <utility>
#include <vector>

using std::numbers::pi;

Ball::Ball(float x, float y, float radius, sf::Color color)
    : m_x{x + radius}, m_y{y + radius}, m_color{color}
{
    setPosition(m_x, m_y);
    setRadius(radius);
    setFillColor(color);
    setOrigin({radius, radius});
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

void Ball::cornerCheck(bool distance, float angle, const Wall &wall)
{
    if (angle >= 0)
    {
        m_x = wall.getLeft() + cos(pi / 2 + angle) * (static_cast<int>(distance) * 10 + getRadius());
        m_y = wall.getTop() - sin(pi / 2 + angle) * (static_cast<int>(distance) * 10 + getRadius());
        std::swap(m_vel_x, m_vel_y);
        m_vel_x *= -1;
        m_vel_y *= -1;
        m_decrease_vel_x *= -1;
        m_decrease_vel_y *= -1;

        return;
    }

    // Determining which side is ball comming from
    if (m_x > m_y)
    {
        // right
        m_x = wall.getLeft() + cos(pi + pi / 4 + angle) * (static_cast<int>(distance) * 10 + getRadius());
        m_y = wall.getTop() - sin(pi + pi / 4 + angle) * (static_cast<int>(distance) * 10 + getRadius());
    }
    else
    {
        // left
        m_x = wall.getLeft() + cos(angle - pi / 4) * (static_cast<int>(distance) * 10 + getRadius());
        m_y = wall.getTop() - sin(angle - pi / 4) * (static_cast<int>(distance) * 10 + getRadius());
    }
}

void Ball::sideCheck(const Wall &wall, float new_x, float new_y)
{
    if ((new_x + getRadius() > wall.getLeft() || new_x - getRadius() > wall.getRight()) &&
        (new_y >= wall.getTop() && new_y <= wall.getBottom()))
    {
        m_vel_x *= -1;
        m_decrease_vel_x *= -1;
    }
    if ((new_y + getRadius() > wall.getTop() || new_y - getRadius() > wall.getBottom()) &&
        (new_x >= wall.getLeft() && new_x <= wall.getRight()))
    {
        m_vel_y *= -1;
        m_decrease_vel_y *= -1;
    }
}

void Ball::checkBounce(const std::vector<Wall> &walls)
{
    for (const auto &wall : walls)
    {
        const float new_x = m_x + m_vel_x;
        const float new_y = m_y + m_vel_y;
        const float angle = bnw::getEquationAngle(getPos(), {new_x, new_y});

        const bool distance = getDistacne(wall.getLeft() - m_vel_x, wall.getTop() - m_vel_y) <= getRadius();
        if (distance)
        {
            cornerCheck(distance, angle, wall);
        }
        else
        {
            sideCheck(wall, new_x, new_y);
        }
    }
}

// Checks if cursor hovers over ball
bool Ball::checkHover(float x, float y) const
{
    return getDistacne(x, y) <= getRadius();
}

void Ball::setSpeed(float x, float y)
{
    m_vel_x          = x / 2;
    m_vel_y          = y / 2;
    m_decrease_vel_x = x / m_friction;
    m_decrease_vel_y = y / m_friction;
}

void Ball::update(const std::vector<Wall> &walls)
{
    if (m_vel_x == 0.0 && m_vel_y == 0.0)
    {
        return;
    }

    // changing directions from boundaries
    if (m_x + m_vel_x < getRadius())
    {
        m_vel_x *= -1;
        m_decrease_vel_x *= -1;
    }
    if (m_y + m_vel_y < getRadius())
    {
        m_vel_y *= -1;
        m_decrease_vel_y *= -1;
    }

    checkBounce(walls);

    m_x += m_vel_x;
    m_y += m_vel_y;

    setPosition({m_x, m_y});

    m_vel_x *= m_friction; // lowering speed
    m_vel_y *= m_friction;

    if (std::abs(m_vel_x) < 0.2 && std::abs(m_vel_y) < 0.2)
    {
        m_vel_x = m_vel_y = 0;
    }
}