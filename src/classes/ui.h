#pragma once

#include "chungus.h"
#include "event.h"
#include "gui.h"

class UI
{
public:
    static void addEvent(const bnw::Event& event);

    // UI();
    void mousePress(Vec2f mouse);
    void update(Vec2f mouse);
    void draw(sf::RenderWindow* window);
    void eventListener();
    void eventHandler();
    void loadGuiScenario(bnw::Scenario scenario);
    void deleteGuiScenario(bnw::Scenario scenario);

private:
    std::vector<GUI>                     m_guis;
    static inline std::queue<bnw::Event> m_event_queue;
};