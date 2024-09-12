#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

namespace bnw
{ // Balls n' Walls

// struct Equation
// {
//     float getX(float y) const
//     {
//         return (y - b) / a;
//     }

//     float getY(float x) const
//     {
//         return a * x + b;
//     }

//     float a{};
//     float b{};
//     float ang{};
// };

// Equation getEquation(sf::Vector2f A, sf::Vector2f B);
float    getAngle(sf::Vector2f A);
float    getDistacne(sf::Vector2f A, sf::Vector2f B);
float    getDistacne(sf::Vector2f A);

} // namespace bnw