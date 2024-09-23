#pragma once

#include "Vec2f.h"
#include <SFML/Graphics.hpp>
#include <cmath>

namespace bnw
{

float getAngle(Vec2f a);
float getDistacne(Vec2f a);
float getDistacne(Vec2f a, Vec2f b);
float dotProduct(Vec2f a, Vec2f b);

} // namespace bnw