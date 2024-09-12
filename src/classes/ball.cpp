#include "ball.h"
#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <cstdlib>
#include <numbers>
#include <utility>
#include <vector>

constexpr float pi{std::numbers::pi_v<float>};

Ball::Ball(sf::Vector2f pos, float radius, sf::Color color)
    : sf::CircleShape{radius}, m_color{color}
{
    setFillColor(color);
    setOrigin(radius, radius);
    setPosition(pos.x + radius, pos.y + radius);
}

// Ball::~Ball() = default;
// make some exsplosion effect

void Ball::cornerCheck(bool distance, float angle, const Wall &wall)
{
    if (angle >= 0)
    {
        setPosition(wall.getLeft() + std::cos(pi / 2 + angle) * (static_cast<float>(distance) * 10 + getRadius()),
                    wall.getTop() - std::sin(pi / 2 + angle) * (static_cast<float>(distance) * 10 + getRadius()));
        std::swap(m_vel.x, m_vel.y);
        m_vel *= -1.0F;

        return;
    }

    // Determining which side is ball comming from
    if (getPosition().x > getPosition().y)
    {
        // right
        setPosition(wall.getLeft() + std::cos(pi * 5 / 4 + angle) * (static_cast<float>(distance) * 10 + getRadius()),
                    wall.getTop() - std::sin(pi * 5 / 4 + angle) * (static_cast<float>(distance) * 10 + getRadius()));
    }
    else
    {
        // left
        setPosition(wall.getLeft() + std::cos(angle - pi / 4) * (static_cast<float>(distance) * 10 + getRadius()),
                    wall.getTop() - std::sin(angle - pi / 4) * (static_cast<float>(distance) * 10 + getRadius()));
    }
}

void Ball::sideCheck(const Wall &wall, sf::Vector2f new_pos)
{
    if ((new_pos.x + getRadius() > wall.getLeft() || new_pos.x - getRadius() > wall.getRight()) &&
        (new_pos.y >= wall.getTop() && new_pos.y <= wall.getBottom()))
    {
        m_vel.x *= -1;
    }
    if ((new_pos.y + getRadius() > wall.getTop() || new_pos.y - getRadius() > wall.getBottom()) &&
        (new_pos.x >= wall.getLeft() && new_pos.x <= wall.getRight()))
    {
        m_vel.y *= -1;
    }
}

void Ball::checkBounce(const std::vector<Wall> &walls)
{
    for (const auto &wall : walls)
    {
        const auto  new_pos = getPosition() + m_vel;
        const float angle   = bnw::getAngle(new_pos);

        const bool distance = bnw::getDistacne({wall.getLeft(), wall.getTop()}, m_vel) <= getRadius();
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
    return bnw::getDistacne(getPosition(), pos) <= getRadius();
}

void Ball::setSpeed(sf::Vector2f speed)
{
    m_vel = speed;
}

void Ball::update(const std::vector<Wall> &walls)
{
    if (m_vel == sf::Vector2f{})
    {
        return;
    }

    // changing directions from boundaries
    // ograniczenia zostana planowane być wzniesione
    if (getPosition().x + m_vel.x < getRadius() || getPosition().x + m_vel.x > 800 - getRadius())
    {
        m_vel.x *= -1;
    }
    if (getPosition().y + m_vel.y < getRadius() || getPosition().y + m_vel.y > 700 - getRadius())
    {
        m_vel.y *= -1;
    }

    checkBounce(walls);

    move(m_vel);

    m_vel *= m_friction; // lowering speed

    if (bnw::getDistacne(m_vel) < 0.2F)
    {
        m_vel = {};
    }
}
