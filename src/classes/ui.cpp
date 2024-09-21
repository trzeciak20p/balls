#include "ui.h"

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

void UI::loadGuiScenario()
{
    std::vector<Button> buttons{};
    buttons.emplace_back(sf::Vector2f{5.F, 5.F}, sf::Vector2f{200.F, 100.F}, "AAAA");
    buttons.emplace_back(sf::Vector2f{400.F, 400.F}, sf::Vector2f{200.F, 100.F}, "bbbb");
    std::vector<Slider> sliders{};
    sliders.emplace_back(sf::Vector2f{100.F, 200.F}, 100, "ziuum");
    sliders.emplace_back(sf::Vector2f{100.F, 400.F}, 100, "ziuum");

    GUI gui = GUI(buttons, sliders);

    m_guis.emplace_back(gui);
}