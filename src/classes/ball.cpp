#include "ball.h"
#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <numbers>
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

void Ball::cornerCheck(const Wall& wall, sf::Vector2f new_pos)
{
    if (new_pos.y >= wall.getTop() && new_pos.y <= wall.getBottom() ||
        new_pos.x >= wall.getLeft() && new_pos.x <= wall.getRight())
    {
        return;
    }

    auto corners = wall.getCorners();

    auto nearest_corner = *std::ranges::min_element(corners, [&](auto cor1, auto cor2) {
        return bnw::getDistacne(cor1, new_pos) < bnw::getDistacne(cor2, new_pos);
    });

    if (bnw::getDistacne(nearest_corner, new_pos) > getRadius())
    {
        return;
    }

    const float dot = bnw::dotProduct(m_vel, nearest_corner - new_pos);
    m_vel -= (nearest_corner - new_pos) / bnw::getDistacne(nearest_corner, new_pos) * dot /
             bnw::getDistacne(nearest_corner, new_pos) * 2.0F;
}

void Ball::sideCheck(const Wall& wall, sf::Vector2f new_pos)
{
    if (new_pos.y >= wall.getTop() && new_pos.y <= wall.getBottom() &&
        ((new_pos.x + getRadius() > wall.getLeft() && new_pos.x < wall.getRight()) ||
         (new_pos.x - getRadius() < wall.getRight() && new_pos.x > wall.getLeft())))
    {
        m_vel.x *= -1;
    }
    if (new_pos.x >= wall.getLeft() && new_pos.x <= wall.getRight() &&
        (new_pos.y + getRadius() > wall.getTop() && new_pos.y < wall.getBottom() ||
         (new_pos.y - getRadius() < wall.getBottom() && new_pos.y > wall.getTop())))
    {
        m_vel.y *= -1;
    }
}

void Ball::checkBounce(const std::vector<Wall>& walls)
{
    for (const auto& wall : walls)
    {
        const auto new_pos = getPosition() + m_vel;

        sideCheck(wall, new_pos);
        cornerCheck(wall, new_pos);
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

void Ball::update(const std::vector<Wall>& walls)
{
    if (m_vel == sf::Vector2f{})
    {
        return;
    }

    checkBounce(walls);

    move(m_vel);

    m_vel *= m_friction; // lowering speed

    if (bnw::getDistacne(m_vel) < 0.2F)
    {
        m_vel = {};
    }
}
