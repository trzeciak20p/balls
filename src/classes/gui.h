#pragma once

#include "button.h"
#include "slider.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class GUI
{
public:
    enum scenario
    {
        menu,
        map_select,
        options,
        hud,
        pause,
        max_gui_scenario
    };

    GUI(GUI::scenario scenario, std::vector<Button> buttons, std::vector<Slider> sliders);

    scenario getScenario();

    void mousePress(sf::Vector2f mouse);
    void update(sf::Vector2f mouse);
    void draw(sf::RenderWindow* window);

private:
    scenario            m_scenario;
    std::vector<Button> m_buttons;
    std::vector<Slider> m_sliders;
};