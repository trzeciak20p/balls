#pragma once

#include "../chungus.h"

class ChargeMeter
{
public:
    void update(Vec2f last_click, Vec2f mouse);
    void draw(sf::RenderWindow* window);

private:
    sf::VertexArray m_vertices{sf::Triangles, 3};
};