#pragma once

#include "ball.h"
#include "gui.h"
#include "simulation.h"
#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Game
{
public:
    explicit Game(sf::RenderWindow* window);

    void  mousePress();
    void  setLastClick();
    void  drawTrail();
    void  mouseRelease();
    Ball* getActiveBall();

    sf::Vector2f getMouse();

    sf::Vector2f m_last_click{};
    Simulation   simulation{};
    GUI          gui{};

private:
    sf::RenderWindow* m_window{};
    bool              m_dragging{};
    Ball*             m_active_ball{};
};