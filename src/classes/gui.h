#pragma once

#include "Vec2f.h"
#include "button.h"
#include "event.h"
#include "slider.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

class GUI
{
public:
    GUI(bnw::Scenario scenario, std::vector<Button>&& buttons, std::vector<Slider>&& sliders);

    bnw::Scenario getScenario();

    void mousePress(Vec2f mouse);
    void update(Vec2f mouse);
    void draw(sf::RenderWindow* window);

private:
    bnw::Scenario       m_scenario;
    std::vector<Button> m_buttons;
    std::vector<Slider> m_sliders;
};