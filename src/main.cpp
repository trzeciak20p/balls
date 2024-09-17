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

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);
    window.setFramerateLimit(60);

    Game gra(&window);
    bnw::loadFont("fonts/comic.ttf");

    buttons.emplace_back(sf::Vector2f{5.F, 5.F}, sf::Vector2f{200.F, 100.F}, "AAAA");
    buttons.emplace_back(sf::Vector2f{400.F, 400.F}, sf::Vector2f{200.F, 100.F}, "bbbb");
    sliders.emplace_back(sf::Vector2f(window.getSize().x / 2, 200), 100, "ziuum");

    Board board("maps/map1");
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

        // Rendering
        window.clear(sf::Color(102, 102, 102));

        switch (gra.getState())
        {
        case Game::map_selection:
        case Game::paused:
            break;
        case Game::menu:
            for (auto &button : buttons)
            {
                if (button.checkHover(gra.getMouse()))
                {
                    button.setActive();
                }
                else
                {
                    Button::clearActive();
                }

                window.draw(button);
                window.draw(button.getText());
            }
            for (auto &slider : sliders)
            {
                if (slider.checkHover(gra.getMouse()))
                {
                    slider.onHover();
                }
                if (Slider::getActive() != nullptr)
                {
                    Slider::getActive()->onUse(gra.getMouse().y);
                }

                window.draw(slider);
                window.draw(slider.getControler());
                window.draw(slider.getText());
            }
            break;

        case Game::playing:
            for (const auto &wall : board.m_walls)
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