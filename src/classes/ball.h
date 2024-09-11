#pragma once

#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Ball : public sf::CircleShape
{
public:
    Ball(sf::Vector2f pos, float radius, sf::Color color = sf::Color::White);

    float getDistacne(sf::Vector2f pos) const;
    void  checkBounce(const std::vector<Wall> &walls);
    void  cornerCheck(bool distance, float angle, const Wall &wall);
    void  sideCheck(const Wall &wall, sf::Vector2f new_pos);
    bool  checkHover(sf::Vector2f pos) const;
    void  setSpeed(sf::Vector2f speed);
    void  update(const std::vector<Wall> &walls);

    sf::Color m_color;

private:
    sf::Vector2f m_vel;
    sf::Vector2f m_decrease_vel;
    float        m_friction{0.9F};
};