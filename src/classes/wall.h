#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <array>

class Wall : public sf::RectangleShape
{
public:
    enum Type : int8_t
    {
        normal = 0 << 1,
        dmg    = 1 << 0,
        bouncy = 1 << 1,
    };

    Wall(sf::Vector2f pos, sf::Vector2f size, Type type = normal);

    float getTop() const;
    float getLeft() const;
    float getRight() const;
    float getBottom() const;

    std::array<sf::Vector2f, 4> getCorners() const;

private:
    Type m_type{};
};