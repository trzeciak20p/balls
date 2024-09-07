#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

class Button
{
private:
    sf::Window *window;
    int pos_x = 0, pos_y = 0;
    sf::Text text{};
    sf::RectangleShape body{};

public:
    Button(int _pos_x, int _pos_y, int _size_x, int _size_y, std::string _name);
    ~Button();

    sf::Text getText();
    sf::RectangleShape getBody();

    void onClick();
    void onHover();
    bool checkHover(sf::Vector2i pos);
};

inline std::vector<Button> buttons; // Vector for storing every class instance