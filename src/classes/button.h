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
    sf::RectangleShape body{};
    sf::Text text{};
    inline static Button *active_button{};

public:
    Button(int _pos_x, int _pos_y, int _size_x, int _size_y, std::string _name);

    void setActive();
    static void clearActive();
    static Button *getActive();

    sf::Text getText();
    sf::RectangleShape getBody();

    void onUse();
    void onHover();
    void onHoverRelease();
    bool checkHover(sf::Vector2i pos);
};

inline std::vector<Button> buttons; // Vector for storing every class instance