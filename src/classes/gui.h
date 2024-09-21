#pragma once

#include "button.h"
#include "slider.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class GUI
{
public:
    GUI(std::string scenario, std::vector<Button> buttons, std::vector<Slider> sliders);

    std::string getScenario();

    void mousePress(sf::Vector2f mouse);
    void update(sf::Vector2f mouse);
    void draw(sf::RenderWindow* window);

private:
    std::string         m_scenario;
    std::vector<Button> m_buttons;
    std::vector<Slider> m_sliders;
};