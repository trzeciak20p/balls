#ifndef BOUNCE_WALL
#define BOUNCE_WALL

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>


class Wall{

    private:
        enum t_type{
            normal,
            dmg,
            bouncy
        };

        int x, y, size_x, size_y;
        t_type type;

    
    public:
        inline static std::vector <Wall> walls;

        sf::RectangleShape body;


        Wall(int _x, int _y, int _size_x, int _size_y, t_type _type = normal);
        ~Wall();

        int getTop();
        int getBottom();
        int getRight();
        int getLeft();

};

#endif //BOUNCe_WALL