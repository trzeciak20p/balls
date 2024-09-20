#pragma once

#include "button.h"
#include "slider.h"
#include <vector>

class GUI
{
public:
    GUI();

    void mousePress(sf::Vector2f mouse);
    void update(sf::Vector2f mouse);
    void draw(sf::RenderWindow* window);

    // private:
    std::vector<Button> m_buttons;
    std::vector<Slider> m_sliders;
};