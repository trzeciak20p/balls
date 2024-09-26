#pragma once

#include "../ui.h"
#include "ball.h"
#include "chargeMeter.h"
#include "wall.h"
#include <SFML/Graphics/RenderTexture.hpp>
#include <vector>

namespace sim
{

class Board
{
public:
    explicit Board(const std::string& path);

    void mousePress(Vec2f mouse);
    void mouseRelease(Vec2f mouse, Vec2f last_click);
    void update(Vec2f last_click, Vec2f mouse);
    void draw(sf::RenderWindow& window);

private:
    Ball*             m_active_ball{};
    ChargeMeter       m_charge_meter;
    std::vector<Wall> m_walls;
    std::vector<Ball> m_balls;
};

} // namespace sim