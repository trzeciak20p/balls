#pragma once

#include "../simulation/board.h"
#include "button.h"

namespace gui
{

class ButThatNeedsBoard : public Button
{
public:
    ButThatNeedsBoard(Vec2f pos, Vec2f size, const std::string& name, sim::Board* board)
        : Button(pos, size, name), m_board{board}
    {
    }

    void setBoard(sim::Board* board)
    {
        m_board = board;
    }

    void mousePress() override
    {
        if (!m_board)
        {
            return;
        }

        // auto color_ball = m_board->m_balls[0].getFillColor();
        // color_ball.r -= 5;
        // m_board->m_balls[0].setFillColor(color_ball);
    }

private:
    sim::Board* m_board{};
};

class ButThatNeedsGame : public Button
{
public:
    ButThatNeedsGame(Vec2f pos, Vec2f size, const std::string& name, Game* game)
        : Button(pos, size, name), m_game{game}
    {
    }

    void mousePress() override
    {
        m_game->getSimulation().loadBoard();
    }

private:
    Game* m_game;
};

} // namespace gui