#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Wall : public sf::RectangleShape
{
public:
    enum class Type : int8_t
    {
        normal = 0 << 1,
        dmg    = 1 << 0,
        bouncy = 1 << 1,
    };

    Wall(sf::Vector2f pos, sf::Vector2f size, Type type = Type::normal);

    float getTop() const;
    float getBottom() const;
    float getRight() const;
    float getLeft() const;

private:
    Type m_type{};
};