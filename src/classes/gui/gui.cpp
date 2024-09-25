#include "gui.h"
#include "../vec2f.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "slider.h"

namespace gui
{

// GUI::GUI(GUI::Scenario scenario, std::vector<std::unique_ptr<Widget>>&& entities)
//     : m_scenario{scenario}, m_entities{std::move(entities)}
// {
// }

// GUI::Scenario GUI::getScenario()
// {
//     return m_scenario;
// }

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

void GUI::draw(sf::RenderWindow& window)
{
    for (auto& entity : m_entities)
    {
        entity->draw(window);
    }
}

} // namespace gui