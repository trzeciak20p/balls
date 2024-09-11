#include "wall.h"

Wall::Wall(sf::Vector2f pos, sf::Vector2f size, Type type)
    : sf::RectangleShape{size}, m_type{type}
{
    if (type == Type::dmg)
    {
        setFillColor(sf::Color(255, 20, 20));
    }
    else if (type == Type::bouncy)
    {
        setFillColor(sf::Color(235, 40, 255));
    }
    else
    {
        setFillColor(sf::Color(125, 125, 125));
    }
    setPosition(pos.x, pos.y);
}

float Wall::getTop() const
{
    return getPosition().y;
}

float Wall::getBottom() const
{
    return getPosition().y + getSize().y;
}

float Wall::getLeft() const
{
    return getPosition().x;
}

float Wall::getRight() const
{
    return getPosition().x + getSize().x;
}