#include "classes/ball.h"
#include "classes/button.h"
#include "classes/fontLoader.h"
#include "classes/game.h"
#include "classes/mapLoader.h"
#include "classes/slider.h"
#include "classes/utils_2d.h"
#include "classes/wall.h"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cmath>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);
    window.setFramerateLimit(60);

    Game gra(&window);
    Ball::initialize(&window);

    loadMap(1);
    bnw::loadFont("../comic.ttf");

    buttons.push_back(Button(5, 5, 200, 100, "AAAA"));
    buttons.push_back(Button(400, 400, 200, 100, "bbbb"));
    sliders.push_back(Slider(window.getSize().x / 2, 200, 100, "ziuum"));

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            gra.updateMouse();
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

        // Rendering
        window.clear(sf::Color(102, 102, 102));

        switch (gra.getState())
        {
        case Game::Game::State::map_selection:
            break;
        case Game::Game::State::paused:
            break;
        case Game::Game::State::menu:
            for (auto &button : buttons)
            {
                if (button.checkHover(gra.mouse))
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
                if (slider.checkHover(gra.mouse))
                {

                    slider.onHover();
                }
                if (Slider::getActive() != nullptr)
                {
                    Slider::getActive()->onUse(gra.mouse.y);
                }

                window.draw(slider.getBody());
                window.draw(slider.getControler());
                window.draw(slider.getText());
            }
            break;

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

        default:
            break;
        }

        window.display();
    }

    return 0;
}