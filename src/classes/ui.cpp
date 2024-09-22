#include "ui.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "button.h"
#include "guiScenarios.h"
#include <vector>

UI::UI()
{
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

void UI::loadGuiScenario(GUI::scenario scenario)
{
    m_guis.emplace_back(getGuiScenario(scenario));
}

void UI::deleteGuiScenario(GUI::scenario scenario)
{
    std::erase_if(m_guis, [&](GUI& gui) { return gui.getScenario() == scenario; });
}
