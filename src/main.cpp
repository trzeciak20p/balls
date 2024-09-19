#include "classes/ball.h"
#include "classes/board.h"
#include "classes/button.h"
#include "classes/fontLoader.h"
#include "classes/game.h"
#include "classes/slider.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cmath>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);
    window.setFramerateLimit(60);

    Game gra(&window);
    bnw::loadFont("fonts/comic.ttf");

    buttons.emplace_back(sf::Vector2f{5.F, 5.F}, sf::Vector2f{200.F, 100.F}, "AAAA");
    buttons.emplace_back(sf::Vector2f{400.F, 400.F}, sf::Vector2f{200.F, 100.F}, "bbbb");
    sliders.emplace_back(sf::Vector2f(window.getSize().x / 2, 200), 100, "ziuum");
    sliders.emplace_back(sf::Vector2f(window.getSize().x / 3 * 2, 200), 100, "ziuum");

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
            for (auto& button : buttons)
            {
                if (button.checkHover(gra.getMouse()))
                {
                    button.setActive();
                }
                else
                {
                    Button::clearActive();
                }

                button.draw(&window);
            }
            for (auto& slider : sliders)
            {
                if (Slider::getActive() != nullptr)
                {
                    Slider::getActive()->onUse(gra.getMouse().y);
                }

                slider.draw(&window);
            }
            break;

        case Game::playing:
            for (const auto& wall : board.m_walls)
            {
                window.draw(wall);
            }

            for (auto& ball : board.m_balls)
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