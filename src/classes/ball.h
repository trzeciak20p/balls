#pragma once

#include "wall.h"
#include "utils_2d.h"

#include <SFML/Graphics.hpp>
#include <cmath>

class Ball
{

private:
    double x, y, vel_x, vel_y, decrease_vel_x, decrease_vel_y;

public:
    inline static sf::Window *window;            // for now using window
    inline static int board_width, board_height; // switching to this when only a part of window will be playfield
    inline static double friction;
    inline static bool movable = true; // tells if ball can be moved
    inline static Ball *active_ball;

    sf::CircleShape body;
    sf::Color color;

    Ball(double _x, double _y, double _size = 20, sf::Color _color = sf::Color::White);
    ~Ball();
    static void initialize(sf::Window *_window); // Initializes classes static variables

    sf::Vector2f getPos();

    double getDistacne(double _x, double _y);
    void checkBounce();
    bool checkHover(double _x, double _y);
    void setSpeed(double _x, double _y);
    void update();
};

inline std::vector<Ball> balls; // Vector for storing every class instance
