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
    Ball(float x, float y, float radius = 20, sf::Color color = sf::Color::White, Board* board = {});

    float        getDistacne(float x, float y) const;
    void         checkBounce();
    sf::Vector2f getPos() const;
    bool         checkHover(float x, float y);
    void         setSpeed(float x, float y);
    void         update();

    sf::CircleShape body;
    sf::Color       m_color;
    Board          *m_board;

private:
    float m_x{};
    float m_y{};
    float m_vel_x{};
    float m_vel_y{};
    float m_decrease_vel_x{};
    float m_decrease_vel_y{};
    float m_friction{0.9f};
};

// void Ball::initialize(sf::Window *_window)
// {
//     Ball::window       = _window;
//     Ball::board_width  = window->getSize().x;
//     Ball::board_height = window->getSize().y;
//     Ball::friction     = 0.9;
// }