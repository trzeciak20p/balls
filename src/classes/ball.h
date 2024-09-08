#pragma once

#include "utils_2d.h"
#include "wall.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class Ball
{
public:
    Ball(float _x, float _y, float _size = 20, sf::Color _color = sf::Color::White);

    static void  initialize(sf::Window *_window); // Initializes classes static variables
    float        getDistacne(float _x, float _y) const;
    void         checkBounce();
    sf::Vector2f getPos() const;
    bool         checkHover(float _x, float _y);
    void         setSpeed(float _x, float _y);
    void         update();

    inline static sf::Window *window;         // for now using window
    inline static bool        movable = true; // tells if ball can be moved
    inline static int         board_width;    // switching to this when only a part of window will be playfield
    inline static int         board_height;   // switching to this when only a part of window will be playfield
    inline static float       friction;
    inline static Ball       *active_ball;

    sf::CircleShape body;
    sf::Color       color;

private:
    float x{};
    float y{};
    float vel_x{};
    float vel_y{};
    float decrease_vel_x{};
    float decrease_vel_y{};
};

inline std::vector<Ball> balls; // Vector for storing every class instance