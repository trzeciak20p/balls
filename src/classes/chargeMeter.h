#pragma once

#include "Vec2f.h"
#include "ball.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class ChargeMeter
{
public:
    void update(bool dragging, Vec2f last_click, Vec2f mouse, Ball* active_ball);
    void draw(sf::RenderWindow* window);

private:
    sf::VertexArray m_vertices{sf::Triangles, 3};
};
