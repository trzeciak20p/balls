#pragma once

#include "ball.h"
#include "chargeMeter.h"
#include "chungus.h"
#include "ui.h"
#include "wall.h"

class Board
{
public:
    explicit Board(const std::string& path);

    void mousePress(Vec2f mouse);
    void update(bool dragging, Vec2f last_click, Vec2f mouse);
    void draw(sf::RenderWindow* window);

private:
    ChargeMeter       m_charge_meter;
    std::vector<Wall> m_walls;
    std::vector<Ball> m_balls;
};