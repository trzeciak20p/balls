#pragma once

#include "../vec2f.h"
#include "ball.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>

namespace sim
{

class ChargeMeter
{
public:
    void update(Ball* active_ball, Vec2f anchor, Vec2f mouse);
    void draw(sf::RenderWindow& window);

private:
    sf::VertexArray m_vertices{sf::Triangles, 3};
};

} // namespace sim