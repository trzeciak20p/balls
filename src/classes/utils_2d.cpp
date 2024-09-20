#include "utils_2d.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace bnw // Balls n' Walls
{

float getAngle(sf::Vector2f a)
{
    return std::atan(a.y / a.x);
}

float getDistacne(sf::Vector2f a, sf::Vector2f b)
{
    return getDistacne(a - b);
}

float getDistacne(sf::Vector2f a)
{
    return std::sqrt(a.x * a.x + a.y * a.y);
}

float dotProduct(sf::Vector2f a, sf::Vector2f b)
{
    return a.x * b.x + a.y * b.y;
}

} // namespace bnw