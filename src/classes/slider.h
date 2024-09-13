#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class Slider
{
private:
    int m_value = 0;
    int *m_reference = nullptr;
    sf::Text m_text{};
    sf::RectangleShape m_body{};
    sf::CircleShape m_ball{};

public:
    Slider(int *reference, std::string name);
};
