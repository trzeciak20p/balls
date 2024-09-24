#pragma once

#include "../chungus.h"
#include "../fontLoader.h"
#include "entity.h"

namespace gui
{

class Button : public Entity, public sf::RectangleShape
{
public:
    Button(Vec2f pos, Vec2f size, const std::string& name);

    void           setActive();
    static void    clearActive();
    static Button* getActive();

    void mousePress();
    void update(Vec2f pos);
    void draw(sf::RenderWindow& window);
    void onUse();
    void colorDefault();
    void colorActive();
    bool checkHover(Vec2f pos);

private:
    static inline Button* m_active_button{};

    sf::Text m_text;
};

} // namespace gui