#include "utils_2d.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace bnw
{ // Balls n' Walls

Equation getEquation(sf::Vector2f A, sf::Vector2f B)
{
    return {(B.y - A.y) / (B.x - A.x), ((B.x * A.y) - (A.x * B.y)) / B.x - A.x, std::atan((B.y - A.y) / (B.x - A.x))};
}

float getEquationAngle(sf::Vector2f A, sf::Vector2f B)
{
    return std::atan((B.y - A.y) / (B.x - A.x));
}

} // namespace bnw