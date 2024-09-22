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

    void mousePress(Vec2f mouse);
    void update(bool dragging, Vec2f last_click, Vec2f mouse);
    void draw(sf::RenderWindow* window);

    std::vector<Ball> m_balls;

private:
    ChargeMeter       m_charge_meter;
    std::vector<Wall> m_walls;
};