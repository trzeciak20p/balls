#include "classes/board.h"
#include "classes/fontLoader.h"
#include "classes/game.h"
#include "classes/ui.h"
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

    UI ui     = UI();
    gra.to_ui = &ui;
    ui.m_buttons.emplace_back(sf::Vector2f{5.F, 5.F}, sf::Vector2f{200.F, 100.F}, "AAAA");
    ui.m_buttons.emplace_back(sf::Vector2f{400.F, 400.F}, sf::Vector2f{200.F, 100.F}, "bbbb");
    ui.m_sliders.emplace_back(sf::Vector2f(window.getSize().x / 2, 200), 100, "ziuum");
    ui.m_sliders.emplace_back(sf::Vector2f(window.getSize().x / 3 * 2, 200), 100, "ziuum");

    Board board("maps/map1");
    gra.to_board = &board;

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

        switch (gra.getState())
        {
        case Game::map_selection:
        case Game::paused:
            break;

        case Game::menu:
            ui.update(gra.getMouse());
            ui.draw(&window);
            break;

        case Game::playing:
            board.update();
            board.draw(&window);
            gra.drawTrail();
            break;

        default:
            break;
        }

        window.display();
    }

    return 0;
}