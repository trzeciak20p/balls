#pragma once

#include "../chungus.h"
#include "entity.h"

namespace gui
{

class Slider : public Entity, public sf::RectangleShape
{
public:
    Slider(Vec2f pos, float size, const std::string& name);

    void           setActive();
    static void    clearActive();
    static Slider* getActive();

    void mousePress();
    void update(Vec2f pos);
    void draw(sf::RenderWindow* window);
    void onUse(float height);
    void colorActive();
    void colorDefault();
    bool checkHover(Vec2f pos);

private:
    inline static Slider* m_active_slider{};

    int                m_value{};
    int                m_size{};
    std::string        m_name;
    sf::Text           m_text;
    sf::RectangleShape m_controler;
};

} // namespace gui