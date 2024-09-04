#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class Wall
{
public:
    enum class Type
    {
        normal,
        dmg,
        bouncy
    };

private:
    int x, y, size_x, size_y;
    Type type;

public:
    inline static std::vector<Wall> walls;

    sf::RectangleShape body;

    Wall(int _x, int _y, int _size_x, int _size_y, Type _type = Type::normal);

    int getTop();
    int getBottom();
    int getRight();
    int getLeft();
};