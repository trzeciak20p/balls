#pragma once

#include "../chungus.h"

class ChargeMeter
{
public:
    void update(Vec2f anchor, Vec2f mouse);
    void draw(sf::RenderWindow* window);

private:
    sf::VertexArray m_vertices{sf::Triangles, 3};
};