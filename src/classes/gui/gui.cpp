#include "gui.h"
#include "../Vec2f.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "button.h"
#include "slider.h"
#include <utility>
#include <vector>

namespace gui
{

GUI::GUI(GUI::Scenario scenario, std::vector<std::unique_ptr<Entity>>&& entities)
    : m_scenario{scenario}, m_entities{std::move(entities)}
{
}

GUI::Scenario GUI::getScenario()
{
    return m_scenario;
}

void GUI::mouseRelease()
{
    Slider::clearActive();
}

void GUI::mousePress(Vec2f mouse)
{
    for (auto& entity : m_entities)
    {
        if (entity->checkHover(mouse))
        {
            entity->mousePress();
        }
    }
}

void GUI::update(Vec2f mouse)
{
    for (auto& entity : m_entities)
    {
        entity->update(mouse);
    }
}

void GUI::draw(sf::RenderWindow* window)
{
    for (auto& entity : m_entities)
    {
        entity->draw(window);
    }
}

} // namespace gui