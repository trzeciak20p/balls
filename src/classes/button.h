#pragma once

#include "chungus.h"
#include "event.h"
#include "fontLoader.h"

class Button : public sf::RectangleShape
{
public:
    Button(Vec2f pos, Vec2f size, const std::string& name, bnw::Event event);

    void           setActive();
    static void    clearActive();
    static Button* getActive();

    void draw(sf::RenderWindow* window);
    void onUse();
    void colorDefault();
    void colorActive();
    bool checkHover(Vec2f pos);

private:
    static inline Button* m_active_button{};

    sf::Text   m_text;
    bnw::Event m_event;
};