#include "gui.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

GUI::GUI()
{
    m_buttons.emplace_back(sf::Vector2f{5.F, 5.F}, sf::Vector2f{200.F, 100.F}, "AAAA");
    m_buttons.emplace_back(sf::Vector2f{400.F, 400.F}, sf::Vector2f{200.F, 100.F}, "bbbb");
    m_sliders.emplace_back(sf::Vector2f{100.F, 200.F}, 100, "ziuum");
    m_sliders.emplace_back(sf::Vector2f{100.F, 400.F}, 100, "ziuum");
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