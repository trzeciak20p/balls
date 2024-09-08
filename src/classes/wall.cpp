#include "wall.h"

Wall::Wall(int _x, int _y, int _size_x, int _size_y, Type _type)
    : x{_x}, y{_y}, size_x{_size_x}, size_y{_size_y}, type{_type}
{
    if (type == Type::dmg)
    {
        body.setFillColor(sf::Color(255, 20, 20));
    }
    else if (type == Type::bouncy)
    {
        body.setFillColor(sf::Color(235, 40, 255));
    }
    else
    {
        body.setFillColor(sf::Color(125, 125, 125));
    }
    body.setPosition(x, y);
    body.setSize(sf::Vector2f(_size_x, _size_y));

    walls.push_back(*this);
}

int Wall::getTop() const
{
    return y;
}

int Wall::getBottom() const
{
    return y + size_y;
}

int Wall::getLeft() const
{
    return x;
}

int Wall::getRight() const
{
    return x + size_x;
}