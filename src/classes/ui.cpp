#include "ui.h"
#include "Vec2f.h"
#include "button.h"
#include "event.h"
#include "guiScenarios.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <queue>
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

void UI::addEvent(const bnw::Event& event)
{
    m_event_queue.emplace(event);
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

void UI::loadGuiScenario(bnw::Scenario scenario)
{
    m_guis.emplace_back(getGuiScenario(scenario));
}

void UI::deleteGuiScenario(bnw::Scenario scenario)
{
    std::erase_if(m_guis, [&](GUI& gui) { return gui.getScenario() == scenario; });
}