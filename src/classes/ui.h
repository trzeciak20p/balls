#pragma once

#include "event.h"
#include "gui/gui.h"
#include "vec2f.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <queue>
#include <vector>

class UI
{
public:
    // UI();

    void mouseRelease();
    void mousePress(Vec2f mouse);
    void update(Vec2f mouse);
    void draw(sf::RenderWindow& window);
    void loadGuiScenario(std::unique_ptr<gui::GUI> gui);
    // void deleteGuiScenario(gui::GUI::Scenario scenario);

private:
    std::vector<std::unique_ptr<gui::GUI>> m_guis;
};