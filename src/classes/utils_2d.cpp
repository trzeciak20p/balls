#include "utils_2d.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace bnw // Balls n' Walls
{

float getAngle(sf::Vector2f A)
{
    return std::atan(A.y / A.x);
}

float getDistacne(sf::Vector2f A, sf::Vector2f B)
{
    return getDistacne(A - B);
}

float getDistacne(sf::Vector2f A)
{
    return std::sqrt(A.x * A.x + A.y * A.y);
}

float dotProduct(sf::Vector2f A, sf::Vector2f B)
{
    return A.x * B.x + A.y * B.y;
}

} // namespace bnw