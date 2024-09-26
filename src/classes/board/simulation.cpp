#include "simulation.h"

Simulation::Simulation() = default;

void Simulation::loadBoard()
{
    m_board = std::make_unique<Board>("maps/map1");
    m_view.move(10 ,0);
}