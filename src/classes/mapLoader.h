#pragma once

#include "ball.h"
#include "board.h"
#include "wall.h"
#include <fstream>
#include <iostream>

// void loadMap(int level);               // Loads built-in maps
void loadMap(Board &board, const std::string &path); // Loads custom maps