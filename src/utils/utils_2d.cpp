#include "utils_2d.h"

namespace bnw
{ // Balls n' Walls
    Equation getEquation(sf::Vector2f A, sf::Vector2f B)
    {
        return Equation{(B.y - A.y) / (B.x - A.x), ((B.x * A.y) - (A.x * B.y)) / B.x - A.x, atan((B.y - A.y) / (B.x - A.x))};
    }
    double getEquationAngle(sf::Vector2f A, sf::Vector2f B)
    {
        return atan((B.y - A.y) / (B.x - A.x));
    }

    float getDistacne(auto x1, auto y1, auto x2, auto y2)
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
} // namespace bnw