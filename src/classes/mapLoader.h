#ifndef BOUNCE_LOAD_MAP
#define BOUNCE_LOAD_MAP

#include <fstream>
#include <iostream>

#include "ball.h"
#include "wall.h"

void loadMap(int level);        // Loads built-in maps
void loadMap(std::string path);     // Loads custom maps


#endif //BOUNCE_LOAD_MAP