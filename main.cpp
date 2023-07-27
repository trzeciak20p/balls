#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <math.h>
#include <iostream>

#include "src/classes/game.h"
 

int main(){

    // Window shouldn't be resizeable as it interferes with checking positions
    sf::RenderWindow window(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);        
    window.setFramerateLimit(60);

    sf::Vector2i mouse;

    Game game(&window);
    Ball::initialize(&window);
    loadMap(1);


    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }else if(event.type == sf::Event::MouseButtonPressed){
                game.mousePress();   
            }
            if(event.type == sf::Event::MouseButtonReleased){
                game.mouseRelease();
            }
        }

        window.clear(sf::Color(102, 102, 102));

        switch(game.getState()){
            case Game::State::menu:
                

                break;

            case Game::State::map_selection:
                


                break;

            case Game::State::settings:
                


                break;

            case Game::State::playing:
                for(auto &i : Wall::walls){
                    window.draw(i.body);
                }

                for(auto &i : Ball::balls){        // updating positions
                    i.update();
                    window.draw(i.body);
                }   

                if(game.calculateTrail()){
                    window.draw(game.trail, 3, sf::Triangles);       
                    window.draw(Ball::active_ball -> body);
                }


                break;

            case Game::State::paused:
                for(auto &i : Wall::walls){
                    window.draw(i.body);
                }

                for(auto &i : Ball::balls){        // drawing without updating
                    window.draw(i.body);
                }   
                break;

            default:
                game.errorReport("DRAW LOOP ERROR");
                break;
        }

        window.display();

    }   

    return EXIT_SUCCESS;
}