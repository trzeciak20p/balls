#pragma once

#include "ball.h"
#include "board.h"
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
    void  update();
    void  draw();
    void  eventHandle(sf::Event event);
    Ball* getActiveBall();

    sf::Vector2f getMouse();

    sf::Vector2f m_last_click{};
    Simulation   simulation{};
    GUI          gui{};
    Board        board{"maps/map1"};

private:
    sf::RenderWindow* m_window{};
    sf::View          m_view{};
    bool              m_dragging{};
    Ball*             m_active_ball{};
};