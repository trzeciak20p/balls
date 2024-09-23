#include "guiScenarios.h"
#include "button.h"
#include "entity.h"
#include "gui.h"
#include "slider.h"
#include <memory>
#include <vector>

namespace gui
{

GUI getGuiScenario(GUI::Scenario scenario)
{
    std::vector<std::unique_ptr<Entity>> entities;

    switch (scenario)
    {
    case GUI::Scenario::menu:
        entities.emplace_back(std::make_unique<Button>(Button(Vec2f{300.F, 150.F}, Vec2f{200.F, 100.F}, "GEJM")));
        entities.emplace_back(std::make_unique<Button>(Button(Vec2f{300.F, 330.F}, Vec2f{200.F, 100.F}, "OPTIONS")));
        break;
    case GUI::Scenario::map_select:

        break;
    case GUI::Scenario::options:
        entities.emplace_back(std::make_unique<Button>(Button({5.F, 5.F}, Vec2f{70.F, 50.F}, "BACK")));
        entities.emplace_back(std::make_unique<Slider>(Slider({350.F, 400.F}, 100, "ziuum")));
        entities.emplace_back(std::make_unique<Slider>(Slider({450.F, 400.F}, 100, "ziuum")));
        break;

    case GUI::Scenario::hud:

        break;
    case GUI::Scenario::pause:

        break;
    default:
        // throw
        break;
    }
    return {scenario, std::move(entities)};
}

} // namespace gui