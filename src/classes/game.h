#pragma once

#include "ball.h"
#include "mapLoader.h"
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

    bool dragging{};
    sf::Vector2i mouse;
    sf::Vertex trail[3];

    Game(sf::Window *window);

    State getState();

    void errorReport(const std::string &err);
    bool calculateTrail(); // Calculates trail for drawing

    void mousePress();
    void mouseRelease();

private:
    sf::Window *window;
    State state;
};
