#include "gui.h"

GUI::GUI(bnw::Scenario scenario, std::vector<Button>&& buttons, std::vector<Slider>&& sliders)
    : m_scenario{scenario}, m_buttons{std::move(buttons)}, m_sliders{std::move(sliders)}
{
}

bnw::Scenario GUI::getScenario()
{
    return m_scenario;
}

void GUI::mousePress(Vec2f mouse)
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

void GUI::update(Vec2f mouse)
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