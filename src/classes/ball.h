#pragma once

#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Ball
{
public:
    inline static sf::Window *window;            // for now using window
    inline static int board_width, board_height; // switching to this when only a part of window will be playfield
    inline static float friction;
    inline static bool movable = true; // tells if ball can be moved
    inline static Ball *active_ball;

    sf::CircleShape body;
    sf::Color color;

    Ball(float _x, float _y, float _size = 20, sf::Color _color = sf::Color::White);
    static void initialize(sf::Window *_window); // Initializes classes static variables

    sf::Vector2f getPos() const;

    float getDistacne(float _x, float _y) const;
    void checkBounce();
    bool checkHover(float _x, float _y);
    void setSpeed(float _x, float _y);
    void update();

private:
    float x, y, vel_x, vel_y, decrease_vel_x{}, decrease_vel_y{};
};

inline std::vector<Ball> balls; // Vector for storing every class instance
