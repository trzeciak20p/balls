#include "classes/board.h"
#include "classes/fontLoader.h"
#include "classes/game.h"
#include "classes/gui.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cmath>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);
    window.setFramerateLimit(60);

    Game gra(&window);
    bnw::loadFont("fonts/comic.ttf");

    gra.gui = GUI();

    sf::View view;
    view.reset(sf::FloatRect(0, 0, 800, 700));
    window.setView(view);

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

            case sf::Event::KeyPressed:
                std::cerr << "kpress: " << sf::Keyboard::getDescription(event.key.scancode).toAnsiString() << '\n';
                view.move(0, 10);
                window.setView(view);
                break;

            case sf::Event::KeyReleased:

            default:
                break;
            }
        }

        // Rendering
        window.clear({102, 102, 102});

        gra.gui.update(gra.getMouse());
        // board.update();

        gra.gui.draw(&window);
        // board.draw(&window);
        gra.drawTrail();

        window.display();
    }
    return 0;
}