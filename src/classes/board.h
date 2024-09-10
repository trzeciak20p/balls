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
    int   m_width{};
    int   m_height{};
    Ball *active_ball{};
    bool  m_balls_movable{true};

    std::vector<Ball> m_balls{};
    std::vector<Wall> m_walls{};
};
