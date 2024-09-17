#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>

class Button : public sf::RectangleShape
{
public:
    Button(sf::Vector2f pos, sf::Vector2f size, const std::string &name);

    void           setActive();
    static void    clearActive();
    static Button *getActive();

    sf::Text getText();

    void onUse();
    void onHover();
    void onHoverRelease();
    bool checkHover(sf::Vector2f pos);

private:
    static inline Button *m_active_button{};

    sf::Text m_text;
};

inline std::vector<Button> buttons; // Vector for storing every class instance