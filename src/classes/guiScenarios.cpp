#include "guiScenarios.h"
#include "button.h"
#include "event.h"
#include "gui.h"
#include "slider.h"
#include <utility>
#include <vector>

GUI getGuiScenario(bnw::Scenario scenario)
{
    std::vector<Button> buttons;
    std::vector<Slider> sliders;

    bnw::Event const la_event{static_cast<bnw::Event::Tag>(bnw::Event::Tag::gui | bnw::Event::Tag::gui_load),
                        bnw::Scenario::options};
    switch (scenario)
    {
    case bnw::Scenario::menu:
        buttons.emplace_back(Vec2f{300.F, 150.F}, Vec2f{200.F, 100.F}, "GEJM", la_event);
        buttons.emplace_back(Vec2f{300.F, 330.F}, Vec2f{200.F, 100.F}, "OPTIONS", la_event);
        break;

    case bnw::Scenario::map_select:

        break;
    case bnw::Scenario::options:
        buttons.emplace_back(Vec2f{5.F, 5.F}, Vec2f{70.F, 50.F}, "BACK", la_event);
        sliders.emplace_back(Vec2f{350.F, 400.F}, 100, "ziuum");
        sliders.emplace_back(Vec2f{450.F, 400.F}, 100, "ziuum");

        break;

    case bnw::Scenario::hud:

        break;
    case bnw::Scenario::pause:

        break;
    default:
        // throw
        break;
    }
    return {scenario, std::move(buttons), std::move(sliders)};
}