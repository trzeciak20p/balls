#include "classes/game.h"
#include "classes/optionsLoader.h"
#include <cmath>

int main()
{
    Game gra;
    OptionsLoader::load();

    gra.gaming();

    return 0;
}