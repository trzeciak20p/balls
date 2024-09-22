#pragma once

#include <SFML/Graphics.hpp>
#include "Vec2f.h"
#include <cmath>

namespace bnw
{ // Balls n' Walls

float getAngle(Vec2f a);
float getDistacne(Vec2f a);
float getDistacne(Vec2f a, Vec2f b);
float dotProduct(Vec2f a, Vec2f b);

} // namespace bnw