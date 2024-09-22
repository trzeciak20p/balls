#include "gui.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "button.h"
#include "slider.h"
#include <vector>

GUI::GUI(GUI::scenario scenario, std::vector<Button> buttons, std::vector<Slider> sliders)
    : m_scenario{scenario}, m_buttons{buttons}, m_sliders{sliders}
{
}

GUI::scenario GUI::getScenario()
{
    return m_scenario;
}

void GUI::mousePress(sf::Vector2f mouse)
{
    for (auto& button : m_buttons)
    {
        if (button.checkHover(mouse))
        {
            button.onUse();
        }
    }
    for (auto& slider : m_sliders)
    {
        if (slider.checkHover(mouse))
        {
            slider.setActive();
        }
    }
}

void GUI::update(sf::Vector2f mouse)
{

    for (auto& button : m_buttons)
    {
        if (button.checkHover(mouse))
        {
            button.setActive();
        }
    }
    for (auto& slider : m_sliders)
    {
        if (Slider::getActive() != nullptr)
        {
            Slider::getActive()->onUse(mouse.y);
        }
    }
}

void GUI::draw(sf::RenderWindow* window)
{
    for (auto& button : m_buttons)
    {
        button.draw(window);
    }
    for (auto& slider : m_sliders)
    {
        slider.draw(window);
    }
}