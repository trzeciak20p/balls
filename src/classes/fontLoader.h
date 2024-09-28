#pragma once

#include <SFML/Graphics/Font.hpp>

namespace bnw
{

inline sf::Font font_default{[]() {
    sf::Font font;
    if (!font.loadFromFile("fonts/comic.ttf"))
    {
        // bad
    }
    return font;
}()};

constexpr int font1_size{20};

} // namespace bnw