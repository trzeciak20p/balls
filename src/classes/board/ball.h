#pragma once

#include "../chungus.h"
#include "ball.h"
#include "wall.h"

class Ball : public sf::CircleShape
{
public:
    Ball(Vec2f pos, float radius, sf::Color color = sf::Color::White);

    void setSpeed(Vec2f speed);
    bool checkHover(Vec2f pos) const;
    void update(const std::vector<Wall>& walls);

    inline static Ball* active_ball{};
    sf::Color           m_color;

private:
    void checkBounce(const std::vector<Wall>& walls);
    void sideCheck(const Wall& wall, Vec2f new_pos);
    void cornerCheck(const Wall& wall, Vec2f new_pos);

    Vec2f m_vel;
    float m_friction{0.9F};
};