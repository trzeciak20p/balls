#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

namespace bnw
{ // Balls n' Walls

float getAngle(sf::Vector2f a);
float getDistacne(sf::Vector2f a);
float getDistacne(sf::Vector2f a, sf::Vector2f b);
float dotProduct(sf::Vector2f a, sf::Vector2f b);

} // namespace bnw