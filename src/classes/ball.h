#pragma once

#include "board.h"
#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Board;

class Ball
{
public:
    Ball(float _x, float _y, float _size = 20, sf::Color color = sf::Color::White, Board* board = {});

    float        getDistacne(float _x, float _y) const;
    void         checkBounce();
    sf::Vector2f getPos() const;
    bool         checkHover(float _x, float _y);
    void         setSpeed(float _x, float _y);
    void         update();

    sf::CircleShape body;
    sf::Color       m_color;
    Board          *m_board;

private:
    float x{};
    float y{};
    float vel_x{};
    float vel_y{};
    float decrease_vel_x{};
    float decrease_vel_y{};
    float friction{0.9f};
};

// void Ball::initialize(sf::Window *_window)
// {
//     Ball::window       = _window;
//     Ball::board_width  = window->getSize().x;
//     Ball::board_height = window->getSize().y;
//     Ball::friction     = 0.9;
// }