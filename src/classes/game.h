#pragma once

#include "simulation/ball.h"
#include "simulation/board.h"
#include "simulation/simulation.h"
#include "simulation/wall.h"
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

    sim::Simulation& getSimulation();

private:
    void eventHandle(sf::Event event);
    void mousePress();
    void mouseRelease();
    void keyPress();

    void update();
    void draw();

    Vec2f getMouse();

    sim::Simulation       m_simulation;
    sf::RenderWindow m_window;
    UI               m_ui;
};