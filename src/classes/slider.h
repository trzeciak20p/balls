#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class Slider
{
private:
    inline static Slider *m_active_slider = nullptr;

    int m_value = 0;
    int m_size = 0;
    std::string m_name = "";
    sf::Vector2f m_pos{0, 0};
    sf::Text m_text{};
    sf::RectangleShape m_body{};
    sf::RectangleShape m_controler{};

public:
    Slider(float pos_x, float pos_y, float size, std::string name);

    void setActive();
    static void clearActive();
    static Slider *getActive();

    sf::Text getText();
    sf::RectangleShape getBody();
    sf::RectangleShape getControler();

    // void update(float value);
    void onUse(float height);
    void onHover();
    void onHoverRelease();
    bool checkHover(sf::Vector2i pos);
};

inline std::vector<Slider> sliders; // Vector for storing every class instance