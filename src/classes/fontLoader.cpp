#include "fontLoader.h"

namespace bnw
{
sf::Font font1{};
void loadFont(std::string path)
{
    if (!font1.loadFromFile(path))
    {
        std::fprintf(stderr, "font: \"%s\" didn't load!\r\n", path.c_str());
    }
}
} // namespace bnw