#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Wall
{
public:
    enum class Type
    {
        normal = 0 << 1,
        dmg    = 1 << 0,
        bouncy = 1 << 1,
    };

    Wall(float x, float y, float size_x, float size_y, Type type = Type::normal);

    float getTop() const;
    float getBottom() const;
    float getRight() const;
    float getLeft() const;

    sf::RectangleShape body{};

private:
    float  m_x{};
    float  m_y{};
    float  m_size_x{};
    float  m_size_y{};
    Type m_type{};
};