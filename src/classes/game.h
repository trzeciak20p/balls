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

    explicit Game(sf::RenderWindow* window);

    State getState();
    void  mousePress();
    void  updateMouse();
    bool  calculateTrail(); // Calculates trail for drawing
    void  mouseRelease();

    sf::Vector2f           getMouse();
    const sf::VertexArray& getTrial();

    sf::Vector2f m_mouse;
    Board*       to_board{};

private:
    sf::RenderWindow* m_window{};
    bool              m_dragging{};
    Ball*             m_active_ball{};
    State             m_state{playing};
    sf::VertexArray   m_trail{sf::Triangles, 3};
};