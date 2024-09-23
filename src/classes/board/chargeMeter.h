#pragma once

#include "../Vec2f.h"
#include "ball.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>

class ChargeMeter
{
public:
    void update(Vec2f last_click, Vec2f mouse);
    void draw(sf::RenderWindow* window);

private:
    sf::VertexArray m_vertices{sf::Triangles, 3};
};