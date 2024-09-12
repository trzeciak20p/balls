#include "classes/ball.h"
#include "classes/board.h"
#include "classes/game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);
    window.setFramerateLimit(60);

    Game gra(&window);

    Board board("../../src/maps/map1");
    gra.to_board = &board;

    while (window.isOpen())
    {
        sf::Event event{};

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                gra.mousePress();
                break;

            case sf::Event::MouseButtonReleased:
                gra.mouseRelease();
                break;

            default:
                break;
            }
        }

        window.clear(sf::Color(102, 102, 102));

        switch (gra.getState())
        {
        case Game::Game::State::playing:
            for (auto &wall : board.m_walls)
            {
                window.draw(wall);
            }

            for (auto &ball : board.m_balls)
            {
                ball.update(board.m_walls);
                window.draw(ball);
            }

            if (gra.calculateTrail())
            {
                window.draw(gra.getTrial());
            }
            break;

        default:
            break;
        }

        window.display();
    }

    return 0;
}
