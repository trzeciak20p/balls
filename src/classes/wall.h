#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <array>
#include <vector>

class Wall : public sf::RectangleShape
{
public:
    enum Type : int8_t
    {
        normal = 0 << 1,
        dmg    = 1 << 0,
        bouncy = 1 << 1,
    };

    Wall(sf::Vector2f left_top, sf::Vector2f width_height, Type type = normal);

    float getTop() const;
    float getLeft() const;
    float getRight() const;
    float getBottom() const;

    std::array<sf::Vector2f, 4> getCorners() const;

private:
    Type m_type{};
};