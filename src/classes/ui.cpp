#include "ui.h"

void UI::mousePress(sf::Vector2f mouse)
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

void UI::update(sf::Vector2f mouse)
{
    Button::clearActive();

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

void UI::draw(sf::RenderWindow* window)
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