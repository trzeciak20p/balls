#include "wall.h"

Wall::Wall(float x, float y, float size_x, float size_y, Type type)
    : m_x{x}, m_y{y}, m_size_x{size_x}, m_size_y{size_y}, m_type{type}
{
    if (type == Type::dmg)
    {
        body.setFillColor(sf::Color(255, 20, 20));
    }
    else if (type == Type::bouncy)
    {
        body.setFillColor(sf::Color(235, 40, 255));
    }
    else
    {
        body.setFillColor(sf::Color(125, 125, 125));
    }
    body.setPosition(x, y);
    body.setSize({size_x, size_y});
}

float Wall::getTop() const
{
    return m_y;
}

float Wall::getBottom() const
{
    return m_y + m_size_y;
}

float Wall::getLeft() const
{
    return m_x;
}

float Wall::getRight() const
{
    return m_x + m_size_x;
}