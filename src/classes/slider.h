#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class Slider : public sf::RectangleShape
{
public:
    Slider(sf::Vector2f pos, float size, const std::string &name);

    void           setActive();
    static void    clearActive();
    static Slider *getActive();

    sf::Text           getText();
    sf::RectangleShape getControler();

    // void update(float value);
    void onUse(float height);
    void onHover();
    void onHoverRelease();
    bool checkHover(sf::Vector2f pos);

private:
    inline static Slider *m_active_slider{};

    int                m_value{};
    int                m_size{};
    std::string        m_name;
    sf::Text           m_text;
    sf::RectangleShape m_controler;
};

inline std::vector<Slider> sliders; // Vector for storing every class instance