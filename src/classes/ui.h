#pragma once

#include "chungus.h"
#include "gui/gui.h"

class UI
{
public:
    // UI();

    void mouseRelease();
    void mousePress(Vec2f mouse);
    void update(Vec2f mouse);
    void draw(sf::RenderWindow* window);
    void loadGuiScenario(gui::GUI::Scenario scenario);
    void deleteGuiScenario(gui::GUI::Scenario scenario);

private:
    std::vector<gui::GUI> m_guis;
};