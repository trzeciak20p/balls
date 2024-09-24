#include "ui.h"
#include "gui/button.h"
#include "gui/gui.h"
#include "gui/guiScenarios.h"

// UI::UI() = default;

void UI::mouseRelease()
{
    for (auto& gui : m_guis)
    {
        gui.mouseRelease();
    }
}

void UI::mousePress(Vec2f mouse)
{
    for (auto& gui : m_guis)
    {
        gui.mousePress(mouse);
    }
}

void UI::update(Vec2f mouse)
{
    gui::Button::clearActive();

    for (auto& gui : m_guis)
    {
        gui.update(mouse);
    }
}

void UI::draw(sf::RenderWindow& window)
{
    for (auto& gui : m_guis)
    {
        gui.draw(window);
    }
}

void UI::loadGuiScenario(gui::GUI::Scenario scenario)
{
    m_guis.emplace_back(gui::getGuiScenario(scenario));
}

void UI::deleteGuiScenario(gui::GUI::Scenario scenario)
{
    std::erase_if(m_guis, [&](gui::GUI& gui) { return gui.getScenario() == scenario; });
}