#ifndef BOUNCE_MAP_LOADER
#define BOUNCE_MAP_LOADER

#include <fstream>
#include <iostream>

#include "ball.h"
#include "wall.h"


void LoadMap(int level);        // Loads built-in maps
void LoadMap(std::string path);     // For loading custom maps made by users 




#endif //BOUNCE_MAP_LOADER