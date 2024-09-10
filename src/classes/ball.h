#pragma once

#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Ball
{
public:
    Ball(float x, float y, float radius = 20, sf::Color color = sf::Color::White);

    float        getDistacne(float x, float y) const;
    void         checkBounce(const std::vector<Wall> &walls);
    sf::Vector2f getPos() const;
    void         cornerCheck(bool distance, float angle, const Wall &wall);
    void         sideCheck(const Wall &wall, float new_x, float new_y);
    bool         checkHover(float x, float y) const;
    void         setSpeed(float x, float y);
    void         update(const std::vector<Wall> &walls);

    sf::CircleShape body;
    sf::Color       m_color;

private:
    float m_x{};
    float m_y{};
    float m_vel_x{};
    float m_vel_y{};
    float m_decrease_vel_x{};
    float m_decrease_vel_y{};
    float m_friction{0.9F};
};