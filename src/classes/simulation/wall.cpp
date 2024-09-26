#include "wall.h"
#include "../vec2f.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <array>

namespace sim
{

Wall::Wall(Vec2f left_top, Vec2f width_height, Type type)
    : sf::RectangleShape{width_height}, m_type{type}
{
    setPosition(left_top);

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

std::array<Vec2f, 4> Wall::getCorners() const
{
    return {{getPosition(), {getRight(), getTop()}, getPosition() + getSize(), {getLeft(), getBottom()}}};
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

} // namespace sim