#include "utils_2d.h"
#include "vec2f.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace bnw
{

float angle(Vec2f a)
{
    return std::atan(a.y / a.x);
}

float getDistance(Vec2f a, Vec2f b)
{
    return getLength(a - b);
}

float getLength(Vec2f a)
{
    return std::sqrt(a.x * a.x + a.y * a.y);
}

float dotProduct(Vec2f a, Vec2f b)
{
    return a.x * b.x + a.y * b.y;
}

} // namespace bnw