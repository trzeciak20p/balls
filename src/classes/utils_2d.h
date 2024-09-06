#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

namespace bnw
{ // Balls n' Walls

    struct Equation
    {
        double a;
        double b;
        double ang;
        double getX(double y)
        {
            return (y - b) / a;
        }
        double getY(double x)
        {
            return a * x + b;
        }
    };

    Equation getEquation(sf::Vector2f A, sf::Vector2f B);
    double getEquationAngle(sf::Vector2f A, sf::Vector2f B);

    template <typename T>
    double getDistacne(T x1, T y1, T x2, T y2);
} // namespace bnw