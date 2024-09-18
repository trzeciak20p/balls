#include "wall.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

Wall::Wall(sf::Vector2f pos, sf::Vector2f size, Type type)
    : sf::RectangleShape{size}, m_type{type}
{
    setPosition(pos);

    switch (type)
    {
    case dmg:
        setFillColor({255, 20, 20});
        break;
    case bouncy:
        setFillColor({235, 40, 255});
        break;
    default:
        setFillColor({125, 125, 125});
        break;
    }
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