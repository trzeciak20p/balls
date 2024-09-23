#pragma once

#include "../chungus.h"

class Wall : public sf::RectangleShape
{
public:
    enum Type : int8_t
    {
        normal = 0 << 1,
        dmg    = 1 << 0,
        bouncy = 1 << 1,
    };

    Wall(Vec2f left_top, Vec2f width_height, Type type = normal);

    float getTop() const;
    float getLeft() const;
    float getRight() const;
    float getBottom() const;

    std::array<Vec2f, 4> getCorners() const;

private:
    Type m_type{};
};