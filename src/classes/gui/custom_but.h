#pragma once

#include "../board/board.h"
#include "button.h"

namespace gui
{

class ButThatNeedsBoard : public Button
{
public:
    ButThatNeedsBoard(Vec2f pos, Vec2f size, const std::string& name, Board* board)
        : Button(pos, size, name), m_board{board}
    {
    }

    void setBoard(Board* board)
    {
        m_board = board;
    }

    void mousePress()
    {
        if (!m_board)
        {
            return;
        }

        auto color_ball = m_board->m_balls[0].getFillColor();
        color_ball.r -= 5;
        m_board->m_balls[0].setFillColor(color_ball);
    }

private:
    Board* m_board{};
};

} // namespace gui