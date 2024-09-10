#pragma once

#include "ball.h"
#include "wall.h"
#include <vector>

class Board
{
public:
    Board(const std::string &path);

    // const std::vector<Wall>& getWalls()
    // {
    //     return m_walls;
    // }

    // private:
    int               m_width{};
    int               m_height{};
    std::vector<Ball> m_balls{};
    Ball             *active_ball{};
    std::vector<Wall> m_walls{};
    bool              m_balls_movable{true};
};
