#include "gui.h"
#include "../vec2f.h"
#include "button.h"
#include "gui_menu.h"
#include "layer.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <utility>
#include <vector>

namespace gui
{

GUI::GUI(Game* game)
{
    loadLayer(createMenuLayer(game));
}

void GUI::mouseRelease()
{
    for (auto& e : m_layers)
    {
        Layer::mouseRelease();
    }
}

void GUI::mousePress(Vec2f mouse)
{
    for (auto& e : m_layers)
    {
        e.mousePress(mouse);
    }
}

void GUI::update(Vec2f mouse)
{
    Button::clearActive();

    for (auto& e : m_layers)
    {
        e.update(mouse);
    }
}

void GUI::draw(sf::RenderWindow& window)
{
    for (auto& e : m_layers)
    {
        e.draw(window);
    }
}

void GUI::loadLayer(Layer&& layer)
{
    m_layers.emplace_back(std::move(layer));
}

} // namespace gui