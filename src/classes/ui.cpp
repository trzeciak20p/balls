#include "ui.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Vec2f.h"
#include "button.h"
#include "guiScenarios.h"
#include <vector>

// UI::UI() = default;

void UI::mousePress(Vec2f mouse)
{
    for (auto& gui : m_guis)
    {
        gui.mousePress(mouse);
    }
}

void UI::update(Vec2f mouse)
{
    Button::clearActive();

    for (auto& gui : m_guis)
    {
        gui.update(mouse);
    }
}

void UI::draw(sf::RenderWindow* window)
{
    for (auto& gui : m_guis)
    {
        gui.draw(window);
    }
}

void UI::addEvent(bnw::Event event)
{
    m_event_queue.emplace();
}

void UI::eventListener()
{
    if (m_event_queue.empty())
    {
        return;
    }
    eventHandler();
}

void UI::eventHandler()
{
    while (!m_event_queue.empty())
    {
        auto event = m_event_queue.front();

        if (event.checkTag(bnw::Event::Tag::gui))
        {
            if (event.checkTag(bnw::Event::Tag::gui_load))
            {
                loadGuiScenario(event.m_gui_scenario);
            }
            else
            {
                deleteGuiScenario(event.m_gui_scenario);
            }
        }
        m_event_queue.pop();
    }
}

void UI::loadGuiScenario(GUI::Scenario scenario)
{
    m_guis.emplace_back(getGuiScenario(scenario));
}

void UI::deleteGuiScenario(GUI::Scenario scenario)
{
    std::erase_if(m_guis, [&](GUI& gui) { return gui.getScenario() == scenario; });
}