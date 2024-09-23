#include "ui.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "Vec2f.h"
#include "gui/button.h"
#include "gui/guiScenarios.h"
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

void UI::loadGuiScenario(GUI::Scenario scenario)
{
    m_guis.emplace_back(getGuiScenario(scenario));
}

void UI::deleteGuiScenario(GUI::Scenario scenario)
{
    std::erase_if(m_guis, [&](GUI& gui) { return gui.getScenario() == scenario; });
}