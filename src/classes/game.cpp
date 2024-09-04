#include "game.h"

Game::Game(sf::Window *_window) : window{_window}
{
    state = State::playing;
    dragging = false;
}

Game::~Game()
{
}

Game::State Game::getState()
{
    return state;
}

void Game::errorReport(std::string err)
{
    std::cout << err << "\r\n";
    state = State::menu;
}