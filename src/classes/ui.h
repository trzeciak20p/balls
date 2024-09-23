#pragma once

#include "Vec2f.h"
#include "gui/gui.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

class UI
{
public:
    // UI();

    void mousePress(Vec2f mouse);
    void update(Vec2f mouse);
    void draw(sf::RenderWindow* window);
    void loadGuiScenario(GUI::Scenario scenario);
    void deleteGuiScenario(GUI::Scenario scenario);

private:
    std::vector<GUI> m_guis;
};