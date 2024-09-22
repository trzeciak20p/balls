#pragma once

#include "Vec2f.h"
#include "event.h"
#include "gui.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <queue>
#include <vector>

class UI
{
public:
    static void addEvent(bnw::Event event);

    // UI();
    void mousePress(Vec2f mouse);
    void update(Vec2f mouse);
    void draw(sf::RenderWindow* window);
    void eventListener();
    void eventHandler();
    void loadGuiScenario(GUI::Scenario scenario);
    void deleteGuiScenario(GUI::Scenario scenario);

private:
    std::vector<GUI>              m_guis;
    static std::queue<bnw::Event> m_event_queue;
};