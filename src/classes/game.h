#pragma once

#include "board/ball.h"
#include "board/board.h"
#include "board/simulation.h"
#include "board/wall.h"
#include "ui.h"
#include "utils_2d.h"
#include "vec2f.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Game
{
public:
    Game();

    void gaming();

    Simulation& getSimulation()
    {
        return m_simulation;
    }

private:
    void eventHandle(sf::Event event);
    void mousePress();
    void mouseRelease();
    void keyPress();

    void update();
    void draw();

    Vec2f getMouse();

    Simulation       m_simulation;
    sf::RenderWindow m_window;
    UI               m_ui;
};