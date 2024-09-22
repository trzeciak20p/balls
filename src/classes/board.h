#pragma once

#include "ball.h"
#include "chargeMeter.h"
#include "wall.h"
#include <SFML/Graphics/RenderTexture.hpp>
#include <vector>

class Board
{
public:
    explicit Board(const std::string& path);

    void update(bool dragging, Vec2f last_click, Vec2f mouse, Ball* active_ball);
    void draw(sf::RenderWindow* window);

    std::vector<Ball> m_balls;
    std::vector<Wall> m_walls;

private:
    ChargeMeter m_charge_meter;
};