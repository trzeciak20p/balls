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

    float getDistacne(int x1, int y1, int x2, int y2)
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    float getDistacne(float x1, float y1, float x2, float y2)
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

}
