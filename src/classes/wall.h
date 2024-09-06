#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class Wall{

    public:
        enum class Type{
        normal = 0 << 1,
        dmg = 1 << 0,
        bouncy = 1 << 1,
    };

    private:     
        int x, y, size_x, size_y;
        Type type;
 
    public: 
        sf::RectangleShape body;


    Wall(int _x, int _y, int _size_x, int _size_y, Type _type = Type::normal);

    int getTop();
    int getBottom();
    int getRight();
    int getLeft();
};

inline std::vector <Wall> walls;
