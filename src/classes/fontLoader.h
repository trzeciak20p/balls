#pragma once

#include <SFML/Graphics/Font.hpp>

namespace bnw
{
inline sf::Font font1;
inline unsigned font1_size{20};
void            loadFont(const std::string &path);

} // namespace bnw