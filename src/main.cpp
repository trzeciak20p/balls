#include "classes/ball.h"
#include "classes/board.h"
#include "classes/button.h"
#include "classes/fontLoader.h"
#include "classes/game.h"
#include "classes/slider.h"
#include "classes/utils_2d.h"
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
    bnw::loadFont("../comic.ttf");

    buttons.push_back(Button(5, 5, 200, 100, "AAAA"));
    buttons.push_back(Button(400, 400, 200, 100, "bbbb"));
    sliders.push_back(Slider(window.getSize().x / 2, 200, 100, "ziuum"));

    Board board("../../src/maps/map1");
    gra.to_board = &board;

    while (window.isOpen())
    {
        sf::Event event{};

        while (window.pollEvent(event))
        {
            gra.updateMouse();

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
            break;
        case Game::paused:
            break;
        case Game::menu:
            for (auto &button : buttons)
            {
                if (button.checkHover(gra.m_mouse))
                {
                    button.setActive();
                }
                else
                {
                    Button::clearActive();
                }

                window.draw(button.getBody());
                window.draw(button.getText());
            }
            for (auto &slider : sliders)
            {
                if (slider.checkHover(gra.m_mouse))
                {

                    slider.onHover();
                }
                if (Slider::getActive() != nullptr)
                {
                    Slider::getActive()->onUse(gra.m_mouse.y);
                }

                window.draw(slider.getBody());
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
