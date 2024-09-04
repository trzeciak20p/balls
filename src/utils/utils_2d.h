#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

namespace bnw
{ // Balls n' Walls

    struct Equation
    {
        float a;
        float b;
        float ang;
        float getX(float y)
        {
            return (y - b) / a;
        };
        float getY(float x)
        {
            return a * x + b;
        }
    };

    Equation getEquation(sf::Vector2f A, sf::Vector2f B);
    double getEquationAngle(sf::Vector2f A, sf::Vector2f B);

    float getDistacne(auto x1, auto y1, auto x2, auto y2);
} // namespace bnw