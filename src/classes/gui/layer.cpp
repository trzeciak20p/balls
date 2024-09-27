#include "layer.h"
#include "../vec2f.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "slider.h"

namespace gui
{

// Layer::Layer(Layer::Scenario scenario, std::vector<std::unique_ptr<Widget>>&& entities)
//     : m_scenario{scenario}, m_widgets{std::move(entities)}
// {
// }

// Layer::Scenario Layer::getScenario()
// {
//     return m_scenario;
// }

void Layer::mouseRelease()
{
    Slider::clearActive();
}

void Layer::mousePress(Vec2f mouse)
{
    for (auto& entity : m_widgets)
    {
        if (entity->checkHover(mouse))
        {
            entity->mousePress();
        }
    }
}

void Layer::update(Vec2f mouse)
{
    for (auto& entity : m_widgets)
    {
        entity->update(mouse);
    }
}

void Layer::draw(sf::RenderWindow& window)
{
    for (auto& entity : m_widgets)
    {
        entity->draw(window);
    }
}

} // namespace gui