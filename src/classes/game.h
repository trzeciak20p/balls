#pragma once

#include "chungus.h"
#include "board.h"
#include "simulation.h"
#include "ui.h"

class Game
{
public:
    explicit Game(sf::RenderWindow* window);

    void mousePress();
    void setLastClick();
    void mouseRelease();
    void update();
    void draw();
    void eventHandle(sf::Event event);

    Vec2f getMouse();

    Vec2f      m_last_click;
    Simulation simulation;
    Board      board{"maps/map1"};

private:
    sf::RenderWindow* m_window{};
    sf::View          m_view;
    bool              m_dragging{};
    UI                m_ui;
};