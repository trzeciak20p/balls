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
    enum class State
    {
        paused,
        playing,
        menu,
        settings,
        map_selection
    };

    explicit Game(sf::Window *window);

    static void errorReport(const std::string &err);
    bool        calculateTrail(); // Calculates trail for drawing
    void        mousePress();
    void        mouseRelease();
    State       getState();

    bool         dragging{};
    sf::Vector2i mouse;
    sf::Vertex   trail[3]{};
    Board       *to_board{};

private:
    sf::Window *m_window{};
    State       m_state{State::playing};
};