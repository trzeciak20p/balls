#include "guiScenarios.h"

GUI getGuiScenario(GUI::scenario scenario)
{
    std::vector<Button> buttons{};
    std::vector<Slider> sliders{};

    switch (scenario)
    {
    case GUI::scenario::menu:
        buttons.emplace_back(sf::Vector2f{5.F, 5.F}, sf::Vector2f{200.F, 100.F}, "AAAA");
        buttons.emplace_back(sf::Vector2f{400.F, 400.F}, sf::Vector2f{200.F, 100.F}, "bbbb");
        sliders.emplace_back(sf::Vector2f{100.F, 200.F}, 100, "ziuum");
        sliders.emplace_back(sf::Vector2f{100.F, 400.F}, 100, "ziuum");
        break;
    case GUI::scenario::map_select:

        break;
    case GUI::scenario::options:
        buttons.emplace_back(sf::Vector2f{600.F, 5.F}, sf::Vector2f{200.F, 100.F}, "opcje1");
        buttons.emplace_back(sf::Vector2f{600.F, 400.F}, sf::Vector2f{200.F, 100.F}, "opcje2");
        sliders.emplace_back(sf::Vector2f{600.F, 200.F}, 200, "ziuum");

        break;

    case GUI::scenario::hud:

        break;
    case GUI::scenario::pause:

        break;
    default:
        // throw
        break;
    }
    return {scenario, buttons, sliders};
}