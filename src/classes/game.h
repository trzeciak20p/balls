#pragma once

#include "gui/gui.h"
#include "simulation/ball.h"
#include "simulation/board.h"
#include "simulation/simulation.h"
#include "simulation/wall.h"
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
    void keyPress(sf::Event::KeyEvent key);
    void onResize(sf::Event::SizeEvent size);

    void update();
    void draw();

    Vec2f getMouse();

    sf::RenderWindow m_window;
    sim::Simulation  m_simulation;
    gui::GUI         m_gui{this};
};