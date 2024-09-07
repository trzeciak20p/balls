#pragma once

#include <SFML/Graphics/Text.hpp>
#include <string>

class Slider
{
private:
    int value;
    int *reference;
    sf::Text text;

public:
    Slider(int *_reference, std::string name);
};
