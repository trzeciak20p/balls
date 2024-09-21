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

void UI::loadGuiScenario(std::string scenario)
{
    std::string path = "./guis/" + scenario;

    std::vector<Button> buttons{};
    buttons.emplace_back(sf::Vector2f{5.F, 5.F}, sf::Vector2f{200.F, 100.F}, "AAAA");
    buttons.emplace_back(sf::Vector2f{400.F, 400.F}, sf::Vector2f{200.F, 100.F}, "bbbb");
    std::vector<Slider> sliders{};
    sliders.emplace_back(sf::Vector2f{100.F, 200.F}, 100, "ziuum");
    sliders.emplace_back(sf::Vector2f{100.F, 400.F}, 100, "ziuum");

    m_guis.emplace_back(GUI(scenario, buttons, sliders));
}

void UI::deleteGuiScenario(std::string scenario)
{
    int i = 0;
    for (std::vector<GUI>::iterator it = m_guis.begin(); it > m_guis.end(); i++)
    {
        if (m_guis[i].getScenario() == scenario)
        {
            m_guis.erase(it);
        }
    }
}
