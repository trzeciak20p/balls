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
    auto diff = A - B;
    return std::sqrt(diff.x * diff.x + diff.y * diff.y);
}

float getDistacne(sf::Vector2f A)
{
    return std::sqrt(A.x * A.x + A.y * A.y);
}

} // namespace bnw
