#pragma once

#include "ball.h"
#include "board.h"
#include "ui.h"
#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Game
{
public:
    enum State : int8_t
    {
        paused,
        playing,
        menu,
        settings,
        map_selection
    };

    explicit Game(sf::RenderWindow* window);

    State getState();
    void  mousePress();
    void  updateMouse();
    void  drawTrail();
    void  mouseRelease();

    sf::Vector2f getMouse();

    sf::Vector2f m_mouse{};
    Board*       to_board{};
    UI*          to_ui{};

private:
    sf::RenderWindow* m_window{};
    bool              m_dragging{};
    Ball*             m_active_ball{};
    State             m_state{playing};
};