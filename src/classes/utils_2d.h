#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

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
    }
    float getY(float x)
    {
        return a * x + b;
    }
};

Equation getEquation(sf::Vector2f A, sf::Vector2f B);
float getEquationAngle(sf::Vector2f A, sf::Vector2f B);

template <typename T> float getDistacne(T x1, T y1, T x2, T y2);
} // namespace bnw