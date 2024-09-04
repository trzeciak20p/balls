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

    float getDistacne(int x1, int y1, int x2, int y2);
    float getDistacne(float x1, float y1, float x2, float y2);

}
