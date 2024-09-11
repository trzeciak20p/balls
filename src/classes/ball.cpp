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

Ball::Ball(sf::Vector2f pos, float radius, sf::Color color)
    : m_color{color}, sf::CircleShape{radius}
{
    setPosition(pos.x + radius, pos.y + radius);
    setFillColor(color);
    setOrigin({radius, radius});
}

// Ball::~Ball() = default;
// make some exsplosion effect

float Ball::getDistacne(sf::Vector2f pos) const
{
    auto ae = getPosition() - pos;
    return std::sqrt(ae.x * ae.x + ae.y * ae.y);
}

void Ball::cornerCheck(bool distance, float angle, const Wall &wall)
{
    if (angle >= 0)
    {
        setPosition(wall.getLeft() + cos(pi / 2 + angle) * (static_cast<int>(distance) * 10 + getRadius()),
                    wall.getTop() - sin(pi / 2 + angle) * (static_cast<int>(distance) * 10 + getRadius()));
        std::swap(m_vel.x, m_vel.y);
        m_vel *= -1.0f;
        m_decrease_vel *= -1.0f;

        return;
    }

    // Determining which side is ball comming from
    if (getPosition().x > getPosition().y)
    {
        // right
        setPosition(wall.getLeft() + cos(pi + pi / 4 + angle) * (static_cast<int>(distance) * 10 + getRadius()),
                    wall.getTop() - sin(pi + pi / 4 + angle) * (static_cast<int>(distance) * 10 + getRadius()));
    }
    else
    {
        // left
        setPosition(wall.getLeft() + cos(angle - pi / 4) * (static_cast<int>(distance) * 10 + getRadius()),
                    wall.getTop() - sin(angle - pi / 4) * (static_cast<int>(distance) * 10 + getRadius()));
    }
}

void Ball::sideCheck(const Wall &wall, sf::Vector2f new_pos)
{
    if ((new_pos.x + getRadius() > wall.getLeft() || new_pos.x - getRadius() > wall.getRight()) &&
        (new_pos.y >= wall.getTop() && new_pos.y <= wall.getBottom()))
    {
        m_vel.x *= -1;
        m_decrease_vel.x *= -1;
    }
    if ((new_pos.y + getRadius() > wall.getTop() || new_pos.y - getRadius() > wall.getBottom()) &&
        (new_pos.x >= wall.getLeft() && new_pos.x <= wall.getRight()))
    {
        m_vel.y *= -1;
        m_decrease_vel.y *= -1;
    }
}

void Ball::checkBounce(const std::vector<Wall> &walls)
{
    for (const auto &wall : walls)
    {
        const auto  new_pos = getPosition() + m_vel;
        const float angle   = bnw::getEquationAngle(getPosition(), new_pos);

        const bool distance = getDistacne({wall.getLeft() - m_vel.x, wall.getTop() - m_vel.y}) <= getRadius();
        if (distance)
        {
            cornerCheck(distance, angle, wall);
        }
        else
        {
            sideCheck(wall, new_pos);
        }
    }
}

// Checks if cursor hovers over ball
bool Ball::checkHover(sf::Vector2f pos) const
{
    return getDistacne(pos) <= getRadius();
}

void Ball::setSpeed(sf::Vector2f speed)
{
    m_vel = speed / 2.0f;
    m_decrease_vel / m_friction;
}

void Ball::update(const std::vector<Wall> &walls)
{
    if (m_vel == sf::Vector2f{})
    {
        return;
    }

    // changing directions from boundaries
    if (getPosition().x + m_vel.x < getRadius())
    {
        m_vel.x *= -1;
        m_decrease_vel.x *= -1;
    }
    if (getPosition().y + m_vel.y < getRadius())
    {
        m_vel.y *= -1;
        m_decrease_vel.y *= -1;
    }

    checkBounce(walls);

    move(m_vel);

    m_vel *= m_friction; // lowering speed

    if (std::abs(m_vel.x) < 0.2 && std::abs(m_vel.y) < 0.2)
    {
        m_vel = {};
    }
}