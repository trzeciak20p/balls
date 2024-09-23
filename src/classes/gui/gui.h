#pragma once

#include "../Vec2f.h"
#include "button.h"
#include "slider.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

class GUI
{
public:
    enum Scenario
    {
        menu,
        map_select,
        options,
        hud,
        pause,
        max_gui_scenario
    };

    GUI(GUI::Scenario scenario, std::vector<Button>&& buttons, std::vector<Slider>&& sliders);

    Scenario getScenario();

    void mouseRelease();
    void mousePress(Vec2f mouse);
    void update(Vec2f mouse);
    void draw(sf::RenderWindow* window);

private:
    Scenario            m_scenario;
    std::vector<Button> m_buttons;
    std::vector<Slider> m_sliders;
};