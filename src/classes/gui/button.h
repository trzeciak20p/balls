#pragma once

#include "../event.h"
#include "../vec2f.h"
#include "entity.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <vector>

namespace gui
{

class Button : public Entity, public sf::RectangleShape
{
public:
    Button(Vec2f pos, Vec2f size, const std::string& name);

    void           setActive();
    static void    clearActive();
    static Button* getActive();

    void mousePress() override;
    void update(Vec2f pos) override;
    void draw(sf::RenderWindow& window) override;
    void onUse();
    void colorDefault() override;
    void colorActive() override;
    bool checkHover(Vec2f pos) override;

private:
    static inline Button* m_active_button{};

    sf::Text m_text;
};

} // namespace gui