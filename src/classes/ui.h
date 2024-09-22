#pragma once

#include "gui.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Vec2f.h"
#include <vector>

class UI
{

public:
    UI();

    void mousePress(Vec2f mouse);
    void update(Vec2f mouse);
    void draw(sf::RenderWindow* window);
    void loadGuiScenario(GUI::scenario scenario);
    void deleteGuiScenario(GUI::scenario scenario);

private:
    std::vector<GUI> m_guis;
};