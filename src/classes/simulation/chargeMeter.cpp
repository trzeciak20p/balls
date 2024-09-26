#include "chargeMeter.h"
#include "../utils_2d.h"
#include "../vec2f.h"
#include "ball.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <cmath>
#include <numbers>

constexpr float pi{std::numbers::pi_v<float>};

namespace sim
{

void ChargeMeter::update(Ball* active_ball, Vec2f anchor, Vec2f mouse)
{
    if (!active_ball)
    {
        m_vertices = sf::VertexArray{sf::Triangles, 3};
        return;
    }
    const float distance = bnw::distance(anchor, mouse);
    const float angle    = bnw::angle(mouse - anchor);
    const float x        = std::cos(angle + pi / 2) * active_ball->getRadius() / 2;
    const float y        = std::sin(angle + pi / 2) * active_ball->getRadius() / 2;

    if (distance < 200)
    {
        const sf::Color trail_color((distance <= 100) ? (distance / 100 * 255) : (255),
                                    (distance >= 100) ? ((100 - distance) / 100 * 255) : (255), 0);
        m_vertices[0] = {active_ball->getPosition() + Vec2f(x, y), trail_color};
        m_vertices[1] = {active_ball->getPosition() - Vec2f(x, y), trail_color};
        m_vertices[2] = {active_ball->getPosition() * 2.0F - mouse, trail_color};

        active_ball->setFillColor(trail_color);
    }
    else
    {
        // speed velocity cap
        m_vertices[0] = {active_ball->getPosition() + Vec2f(x, y), sf::Color::Red};
        m_vertices[1] = {active_ball->getPosition() - Vec2f(x, y), sf::Color::Red};

        const float tip_x = std::cos(angle) * 200;
        const float tip_y = std::sin(angle) * 200;

        if (mouse.x < active_ball->getPosition().x + 2.5F)
        {
            m_vertices[2] = {active_ball->getPosition() + Vec2f(tip_x, tip_y), sf::Color::Red};
        }
        else
        {
            m_vertices[2] = {active_ball->getPosition() - Vec2f(tip_x, tip_y), sf::Color::Red};
        }
        active_ball->setFillColor(sf::Color::Red);
    }
}

void ChargeMeter::draw(sf::RenderWindow& window)
{
    window.draw(m_vertices);
}

} // namespace sim