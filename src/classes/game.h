#pragma once

#include "ball.h"
#include "board.h"
#include "simulation.h"
#include "ui.h"
#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include "Vec2f.h"
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

    Vec2f getMouse();

    Vec2f m_last_click{};
    Simulation   simulation{};
    Board        board{"maps/map1"};

private:
    sf::RenderWindow* m_window{};
    sf::View          m_view;
    bool              m_dragging{};
    Ball*             m_active_ball{};
    UI                m_ui;
};