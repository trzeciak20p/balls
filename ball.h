#ifndef BOUNCE_BALL
#define BOUNCE_BALL

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>

// #include "functions.cpp"
#include "wall.h"


class Ball{

    private:
        float x, y, vel_x, vel_y, decrease_vel_x, decrease_vel_y;

    public:
        inline static sf::Window *window;       // for now using window
        inline static int H, W;        // switching to this when only a part of window will be playfield
        inline static float friction;
        inline static bool movable = true;      // tells if ball can be moved
        inline static Ball *active_ball;
        inline static std::vector <Ball> balls;     // Vector for storing every class instance

        sf::CircleShape body;
        sf::Color color;


        Ball(float _x, float _y, float size = 20, sf::Color color = sf::Color::White);
        ~Ball();

        sf::Vector2f getPos();

        float getDistacne(float _x, float _y);
        void checkBounce();
        bool checkHover(float _x, float _y);
        void setSpeed(float _x, float _y);
        void update();

};    

#endif //BOUNCE_BALL