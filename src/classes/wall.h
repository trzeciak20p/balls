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

    Wall(int x, int y, int size_x, int size_y, Type type = Type::normal);

    int getTop() const;
    int getBottom() const;
    int getRight() const;
    int getLeft() const;

    sf::RectangleShape body{};

private:
    int  m_x{};
    int  m_y{};
    int  m_size_x{};
    int  m_size_y{};
    Type m_type{};
};