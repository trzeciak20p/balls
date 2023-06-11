#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>


class Ball{

    private:
        float x, y, vel_x, vel_y;

    public:
        inline static sf::Window *window;       // for now using window
        inline static int H , W;        // switching to this when only a part of window will be playfield
        inline static float friction;
        inline static bool movable = true;
        inline static Ball *active_ball;      // coul be reference but could be not
        inline static std::vector <Ball> balls;

        sf::CircleShape body;
        sf::Color color;



        Ball(float _x, float _y, float size = 20, sf::Color color = sf::Color::White);
        ~Ball();


        sf::Vector2f getPos();
        bool checkRange(float _x, float _y);
        void setSpeed(float _x, float _y);
        void update();

};    
