#pragma once

#include "ball.h"
#include "board.h"
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

    explicit Game(sf::Window *window);

    State getState();
    void  mousePress();
    void  updateMouse();
    void  mouseRelease();
    bool  calculateTrail(); // Calculates trail for drawing

    const sf::VertexArray &getTrial();

    sf::Vector2i m_mouse;
    Board       *to_board{};

private:
    sf::Window     *m_window{};
    bool            m_dragging{};
    Ball           *m_active_ball{};
    State           m_state{menu};
    sf::VertexArray m_trail{sf::Triangles, 3};
};