#include "classes/ball.h"
#include "classes/game.h"
#include "classes/mapLoader.h"
#include "classes/wall.h"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);
    window.setFramerateLimit(60);

    Game gra(&window);

    Ball::initialize(&window);

    loadMap(1);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                gra.mousePress();
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                gra.mouseRelease();
            }
        }

        window.clear(sf::Color(102, 102, 102));

        switch (gra.getState())
        {
        case Game::Game::State::playing:
            for (auto &i : walls)
            {
                window.draw(i.body);
            }

            for (auto &i : balls)
            { // updating positions
                i.update();
                window.draw(i.body);
            }

            if (gra.calculateTrail())
            {
                window.draw(gra.trail, 3, sf::Triangles);
            }
            break;
        }

        window.display();
    }

    return 0;
}