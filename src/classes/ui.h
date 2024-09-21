#pragma once

#include "gui.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class UI
{

public:
    UI();

    void mousePress(sf::Vector2f mouse);
    void update(sf::Vector2f mouse);
    void draw(sf::RenderWindow* window);
    void loadGuiScenario();

private:
    std::vector<GUI> m_guis;
};