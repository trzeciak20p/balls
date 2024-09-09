#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

namespace bnw
{ // Balls n' Walls

struct Equation
{
    float getX(float y)
    {
        return (y - b) / a;
    }

    float getY(float x)
    {
        return a * x + b;
    }

    float a;
    float b;
    float ang;
};

Equation getEquation(sf::Vector2f A, sf::Vector2f B);
float    getEquationAngle(sf::Vector2f A, sf::Vector2f B);

template <typename T>
float getDistacne(T x1, T y1, T x2, T y2)
{
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

} // namespace bnw