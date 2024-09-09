#include "wall.h"

Wall::Wall(int x, int y, int size_x, int size_y, Type type)
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
    body.setSize(sf::Vector2f(size_x, size_y));
}

int Wall::getTop() const
{
    return m_y;
}

int Wall::getBottom() const
{
    return m_y + m_size_y;
}

int Wall::getLeft() const
{
    return m_x;
}

int Wall::getRight() const
{
    return m_x + m_size_x;
}