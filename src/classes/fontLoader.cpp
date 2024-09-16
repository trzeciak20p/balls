#include "fontLoader.h"

namespace bnw
{
// klasa z tego miałaby sens
sf::Font font1{};
int font1_size = 20;
void loadFont(std::string path)
{
    if (!font1.loadFromFile(path))
    {
        std::fprintf(stderr, "font: \"%s\" didn't load!\r\n", path.c_str());
    }
}
} // namespace bnw