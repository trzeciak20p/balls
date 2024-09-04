#pragma once

#include "ball.h"
#include "wall.h"

#include <fstream>
#include <iostream>

void loadMap(int level);        // Loads built-in maps
void loadMap(std::string path); // Loads custom maps