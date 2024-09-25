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
    void loadBoard();

private:
    void mousePress();
    void setLastClick();
    void mouseRelease();
    void update();
    void draw();
    void keyPress();
    void eventHandle(sf::Event event);

    Vec2f getMouse();

    Simulation             m_simulation;
    std::unique_ptr<Board> m_board{};
    Vec2f                  m_last_click;
    sf::RenderWindow       m_window;
    sf::View               m_view;
    UI                     m_ui;
};