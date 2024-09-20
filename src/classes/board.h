#pragma once

#include "ball.h"
#include "wall.h"
#include <SFML/Graphics/RenderTexture.hpp>
#include <vector>

class Board
{
public:
    explicit Board(const std::string& path);

    void update();
    void draw(sf::RenderWindow* window);

    std::vector<Ball> m_balls;
    std::vector<Wall> m_walls;
};