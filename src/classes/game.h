#pragma once

#include "board/board.h"
#include "board/simulation.h"
#include "chungus.h"
#include "ui.h"

class Game
{
public:
    Game();

    void gaming();

private:
    void mousePress();
    void setLastClick();
    void mouseRelease();
    void update();
    void draw();
    void eventHandle(sf::Event event);

    Vec2f getMouse();

    Simulation       m_simulation;
    Board            m_board{"maps/map1"};
    Vec2f            m_last_click;
    sf::RenderWindow m_window;
    sf::View         m_view;
    UI               m_ui;
};