#pragma once

#include "vec2f.h"
#include <SFML/Graphics.hpp>
#include <cmath>

namespace bnw
{

float angle(Vec2f a);
float length(Vec2f a);
float distance(Vec2f a, Vec2f b);
float dotProduct(Vec2f a, Vec2f b);

} // namespace bnw