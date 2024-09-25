#pragma once

#include "../utils_2d.h"
#include "../vec2f.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <cmath>

class Ball : public sf::CircleShape
{
public:
    Ball(Vec2f pos, float radius, sf::Color base_color = sf::Color::White);

    void      setSpeed(Vec2f speed);
    bool      checkHover(Vec2f mouse) const;
    void      update(const std::vector<Wall>& walls);
    sf::Color getBaseColor();

private:
    void checkBounce(const std::vector<Wall>& walls);
    void sideCheck(const Wall& wall, Vec2f new_pos);
    void cornerCheck(const Wall& wall, Vec2f new_pos);

    sf::Color m_base_color;
    Vec2f     m_vel;
    float     m_friction{0.9F};
};