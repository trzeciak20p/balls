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

    Wall(int _x, int _y, int _size_x, int _size_y, Type _type = Type::normal);

    int getTop() const;
    int getBottom() const;
    int getRight() const;
    int getLeft() const;

    sf::RectangleShape body;

private:
    int  x;
    int  y;
    int  size_x;
    int  size_y;
    Type type;
};

inline std::vector<Wall> walls;