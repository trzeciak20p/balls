#pragma once

#include "Vec2f.h"
#include "board/board.h"
#include "board/simulation.h"
#include "board/wall.h"
#include "ui.h"
#include "utils_2d.h"
#include <SFML/Graphics.hpp>
#include <cmath>

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

    Simulation simulation;
    Board      board{"maps/map1"};

private:
    Vec2f             m_last_click;
    sf::RenderWindow* m_window{};
    sf::View          m_view;
    UI                m_ui;
};