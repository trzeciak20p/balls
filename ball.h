#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>


class Ball{

    private:
        float x, y, vel_x, vel_y;

    public:
        inline static sf::Window *window;
        inline static int H , W;
        inline static float friction;
        inline static bool movable = true;
        inline static Ball *active_ball;
        sf::CircleShape body;
        sf::Color color;



        Ball(float _x, float _y, float size = 20, sf::Color color = sf::Color::White);
        ~Ball();

        int getx();
        int gety();

        sf::Vector2f getPos();
        bool checkRange(float _x, float _y);
        void setSpeed(float _x, float _y);
        void update();

};    
