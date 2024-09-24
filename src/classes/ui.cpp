#include "ui.h"
#include "gui/button.h"
#include "vec2f.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <utility>
#include <vector>

// UI::UI() = default;

void UI::mouseRelease()
{
    for (auto& gui : m_guis)
    {
        gui->mouseRelease();
    }
}

void UI::mousePress(Vec2f mouse)
{
    for (auto& gui : m_guis)
    {
        gui->mousePress(mouse);
    }
}

void UI::update(Vec2f mouse)
{
    gui::Button::clearActive();

    for (auto& gui : m_guis)
    {
        gui->update(mouse);
    }
}

void UI::draw(sf::RenderWindow& window)
{
    for (auto& gui : m_guis)
    {
        gui->draw(window);
    }
}

void UI::loadGuiScenario(std::unique_ptr<gui::GUI> gui)
{
    m_guis.emplace_back(std::move(gui));
}

// void UI::deleteGuiScenario(gui::GUI::Scenario scenario)
// {
//     std::erase_if(m_guis, [&](gui::GUI& gui) { return gui.getScenario() == scenario; });
// }