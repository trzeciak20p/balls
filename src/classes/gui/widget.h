#pragma once

#include "../vec2f.h"
#include <SFML/Graphics/RenderWindow.hpp>

namespace gui
{

class Widget
{
public:
    virtual ~Widget() = default;

    virtual void mousePress()                   = 0;
    virtual void update(Vec2f pos)              = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void colorActive()                  = 0;
    virtual void colorDefault()                 = 0;
    virtual bool checkHover(Vec2f pos)          = 0;
};

} // namespace gui