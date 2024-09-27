#pragma once

#include "../vec2f.h"
#include "layer.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <queue>
#include <vector>

class Game;

namespace gui
{

class GUI
{
public:
    explicit GUI(Game* game);

    void mouseRelease();
    void mousePress(Vec2f mouse);
    void update(Vec2f mouse);
    void draw(sf::RenderWindow& window);
    void loadLayer(Layer&& layer);

private:
    std::vector<Layer> m_layers;
};

} // namespace gui