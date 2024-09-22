#include "guiScenarios.h"
#include "button.h"
#include "event.h"
#include "gui.h"
#include "slider.h"
#include <vector>

GUI getGuiScenario(GUI::Scenario scenario)
{
    std::vector<Button> buttons;
    std::vector<Slider> sliders;

    switch (scenario)
    {
    case GUI::Scenario::menu:
        buttons.emplace_back(Vec2f{300.F, 150.F}, Vec2f{200.F, 100.F}, "GEJM");
        buttons.emplace_back(Vec2f{300.F, 330.F}, Vec2f{200.F, 100.F}, "OPTIONS",
                             bnw::Event(static_cast<bnw::Event::Tag>(bnw::Event::Tag::gui | bnw::Event::Tag::gui_load),
                                        GUI::Scenario::options));
        break;
    case GUI::Scenario::map_select:

        break;
    case GUI::Scenario::options:
        buttons.emplace_back(Vec2f{5.F, 5.F}, Vec2f{70.F, 50.F}, "BACK");
        sliders.emplace_back(Vec2f{350.F, 400.F}, 100, "ziuum");
        sliders.emplace_back(Vec2f{450.F, 400.F}, 100, "ziuum");

        break;

    case GUI::Scenario::hud:

        break;
    case GUI::Scenario::pause:

        break;
    default:
        // throw
        break;
    }
    return {scenario, std::move(buttons), std::move(sliders)};
}