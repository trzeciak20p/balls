#include "ball.h"
#include "../utils_2d.h"

Ball::Ball(Vec2f pos, float radius, sf::Color color)
    : sf::CircleShape{radius}, m_color{color}
{
    setFillColor(color);
    setOrigin(radius, radius);
    setPosition(pos.x + radius, pos.y + radius);
}

void Ball::cornerCheck(const Wall& wall, Vec2f new_pos)
{
    if (new_pos.y >= wall.getTop() && new_pos.y <= wall.getBottom() ||
        new_pos.x >= wall.getLeft() && new_pos.x <= wall.getRight())
    {
        return;
    }

    auto corners = wall.getCorners();

    auto nearest_corner = *std::ranges::min_element(
        corners, [&](auto cor1, auto cor2) { return bnw::getLength(cor1, new_pos) < bnw::getLength(cor2, new_pos); });

    if (bnw::getLength(nearest_corner, new_pos) > getRadius())
    {
        return;
    }

    const float dot = bnw::dotProduct(m_vel, nearest_corner - new_pos);
    m_vel -= (nearest_corner - new_pos) / bnw::getLength(nearest_corner, new_pos) * dot /
             bnw::getLength(nearest_corner, new_pos) * 2.0F;
}

void Ball::sideCheck(const Wall& wall, Vec2f new_pos)
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

bool Ball::checkHover(Vec2f mouse) const
{
    return bnw::getLength(getPosition(), mouse) <= getRadius();
}

void Ball::setSpeed(Vec2f speed)
{
    m_vel = speed;
}

void Ball::update(const std::vector<Wall>& walls)
{
    if (m_vel == Vec2f{})
    {
        return;
    }

    checkBounce(walls);
    move(m_vel);

    m_vel *= m_friction; // lowering speed

    if (bnw::getDistance(m_vel) < 0.2F)
    {
        m_vel = {};
    }
}
