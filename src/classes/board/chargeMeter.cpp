#include "chargeMeter.h"
#include "../utils_2d.h"
#include "ball.h"

constexpr float pi{std::numbers::pi_v<float>};

void ChargeMeter::update(Vec2f anchor, Vec2f mouse)
{

    if (Ball::active_ball == nullptr)
    {
        m_vertices = sf::VertexArray{sf::Triangles, 3};
        return;
    }
    const float distance = bnw::getDistance(anchor, mouse);
    const float angle    = bnw::getAngle(mouse - anchor);
    const float x        = std::cos(angle + pi / 2) * Ball::active_ball->getRadius() / 2;
    const float y        = std::sin(angle + pi / 2) * Ball::active_ball->getRadius() / 2;

    if (distance < 200)
    {
        const sf::Color trail_color((distance <= 100) ? (distance / 100 * 255) : (255),
                                    (distance >= 100) ? ((100 - distance) / 100 * 255) : (255), 0);
        m_vertices[0] = {Ball::active_ball->getPosition() + Vec2f(x, y), trail_color};
        m_vertices[1] = {Ball::active_ball->getPosition() - Vec2f(x, y), trail_color};
        m_vertices[2] = {Ball::active_ball->getPosition() * 2.0F - mouse, trail_color};

        Ball::active_ball->setFillColor(trail_color);
    }
    else
    {
        // speed velocity cap
        m_vertices[0] = {Ball::active_ball->getPosition() + Vec2f(x, y), sf::Color::Red};
        m_vertices[1] = {Ball::active_ball->getPosition() - Vec2f(x, y), sf::Color::Red};

        const float tip_x = std::cos(angle) * 200;
        const float tip_y = std::sin(angle) * 200;

        if (mouse.x < Ball::active_ball->getPosition().x + 2.5F)
        {
            m_vertices[2] = {Ball::active_ball->getPosition() + Vec2f(tip_x, tip_y), sf::Color::Red};
        }
        else
        {
            m_vertices[2] = {Ball::active_ball->getPosition() - Vec2f(tip_x, tip_y), sf::Color::Red};
        }
        Ball::active_ball->setFillColor(sf::Color::Red);
    }
}

void ChargeMeter::draw(sf::RenderWindow* window)
{
    window->draw(m_vertices);
}