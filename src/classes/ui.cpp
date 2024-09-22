#include "ui.h"
#include "fstream"
#include "guiScenarios.h"
#include "iostream"

UI::UI()
{
}

void UI::mousePress(sf::Vector2f mouse)
{
    for (auto& gui : m_guis)
    {
        gui.mousePress(mouse);
    }
}

void UI::update(sf::Vector2f mouse)
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
