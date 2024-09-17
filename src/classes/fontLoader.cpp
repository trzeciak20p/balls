#include "fontLoader.h"
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <string>

namespace bnw
{
// klasa z tego miałaby sans

void loadFont(const std::string &path)
{
    if (!font1.loadFromFile(path))
    {
        std::cerr << "font: " << path << " didn't load!\n";
    }
}
} // namespace bnw