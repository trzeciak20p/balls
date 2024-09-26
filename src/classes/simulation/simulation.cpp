#include "simulation.h"
#include "../vec2f.h"
#include "board.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <memory>

namespace sim
{

void Simulation::loadBoard()
{
    m_board = std::make_unique<Board>("maps/map1");
    m_view.move(10, 0);
}

void Simulation::draw(sf::RenderWindow& window)
{
    if (!m_board)
    {
        return;
    }

    window.setView(m_view);
    m_board->draw(window);
    window.setView(window.getDefaultView());
}

Vec2f Simulation::wetWouse(sf::RenderWindow& window, Vec2f mouse)
{
    const sf::Vector2i pixel_pos = sf::Mouse::getPosition(window);

    return window.mapPixelToCoords(sf::Vector2i(mouse), m_view);
}

void Simulation::update(sf::RenderWindow& window, Vec2f mouse)
{
    if (!m_board)
    {
        return;
    }
    m_board->update(m_last_click, wetWouse(window, mouse));
}

void Simulation::mousePress(sf::RenderWindow& window, Vec2f mouse)
{
    if (!m_board)
    {
        return;
    }

    m_last_click = wetWouse(window, mouse);
    m_board->mousePress(wetWouse(window, mouse));
}

void Simulation::onResize(sf::Event::SizeEvent size)
{
    m_view.setSize(size.width, size.height);
}

void Simulation::mouseRelease(sf::RenderWindow& window, Vec2f mouse)
{
    if (!m_board)
    {
        return;
    }

    m_board->mouseRelease(wetWouse(window, mouse), m_last_click);
}

} // namespace sim