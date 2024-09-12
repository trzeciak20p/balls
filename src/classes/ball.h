#pragma once

#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Ball final : public sf::CircleShape
{
public:
    Ball(sf::Vector2f pos, float radius, sf::Color color = sf::Color::White);

    void setSpeed(sf::Vector2f speed);
    bool checkHover(sf::Vector2f pos) const;
    void update(const std::vector<Wall> &walls);
    void checkBounce(const std::vector<Wall> &walls);
    void sideCheck(const Wall &wall, sf::Vector2f new_pos);
    void cornerCheck(bool distance, float angle, const Wall &wall);

    sf::Color m_color;

private:
    sf::Vector2f m_vel;
    float        m_friction{0.9F};
};
