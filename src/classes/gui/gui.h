#pragma once

#include "../vec2f.h"
#include "button.h"
#include "entity.h"
#include "event.h"
#include "slider.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>

namespace gui
{

class GUI
{
public:
    enum Scenario
    {
        menu,
        map_select,
        options,
        hud,
        pause,
        max_gui_scenario
    };

    // GUI(GUI::Scenario scenario, std::vector<std::unique_ptr<Entity>>&& entities);

    virtual ~GUI() = default;

    // Scenario getScenario();

    static void mouseRelease();
    void        mousePress(Vec2f mouse);
    void        update(Vec2f mouse);
    void        draw(sf::RenderWindow& window);

protected:
    // Scenario                             m_scenario;
    std::vector<std::unique_ptr<Entity>> m_entities;
};

} // namespace gui