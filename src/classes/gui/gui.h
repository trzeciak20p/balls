#pragma once

#include "../Vec2f.h"
#include "entity.h"
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

    GUI(GUI::Scenario scenario, std::vector<std::unique_ptr<Entity>>&& entities);

    Scenario getScenario();

    void mouseRelease();
    void mousePress(Vec2f mouse);
    void update(Vec2f mouse);
    void draw(sf::RenderWindow* window);

private:
    Scenario                             m_scenario;
    std::vector<std::unique_ptr<Entity>> m_entities;
};

} // namespace gui