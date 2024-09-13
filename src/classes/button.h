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
    sf::Vector2i m_pos{0, 0};
    sf::RectangleShape m_body{};
    sf::Text m_text{};
    inline static Button *m_active_button{};

public:
    Button(int pos_x, int pos_y, int size_x, int size_y, std::string name);

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