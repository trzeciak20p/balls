#include "mapLoader.h"


sf::Color ConvertToSFColor(std::string &str){
    if(str == "col()")
        return sf::Color::White;

    std::cout << "str: " << str << "\r\n";
    unsigned char color[3];
    unsigned char index = str.find(",");
    color[0] = std::stoi( str.substr(4, index - 4) );
    unsigned char index2 = str.substr(++index).find(",") + index;
    color[1] = std::stoi( str.substr(index, index2 - index) );
    index = str.substr(++index2).find(")") + index2;
    color[2] = std::stoi( str.substr(index2, index - index2) );
    return sf::Color(color[0], color[1], color[2]);
}

void LoadMap(int level){

    Ball::balls.clear();
    Wall::walls.clear();

    std::fstream file;
    std::string path = "../maps/map";
    path += char(level + '0');

    file.open(path, std::ios::in);
    if(!file.good()){
        return;
    }
    
    char obj;

    while(file >> obj){
        if(obj == 'b'){
            float x, y, r;
            file >> x; file >> y; file >> r;

            // Data check
            // if(x < 0)
            //     x *= -1;
            // if(y < 0)
            //     y *= -1;
            // if(r < 0)
            //     r *= -1;
            // if(r <= 0)
            //     r = 50;

            std::string color_str;
            file >> color_str;
            sf::Color color = ConvertToSFColor(color_str);
            Ball(x, y, r, color);
            std::cout << "kolorek" << color.r << ", " << color.g << ", " << color.b << "\r\n";

        }else if(obj == 'w'){
            float x, y, x_size, y_size;
            file >> x; file >> y; file >> x_size; file >> y_size;


        }else{
            file.close();
            // return error
            return;
        }

    }
    
    file.close();
    
}

void LoadMap(std::string file){

    LoadMap(1);

}
