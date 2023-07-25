#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <math.h>
#include <iostream>

#include "src/utils/utils_2d.h"
#include "src/classes/mapLoader.h"
#include "src/classes/ball.h"
#include "src/classes/wall.h"


int main(){

    // Window szouldn't be resizeable as it interferes with checking positions
    sf::RenderWindow window(sf::VideoMode(800, 700), "Balls and Walls", sf::Style::Close);        
    window.setFramerateLimit(60);

    sf::Vector2i mouse;

    bool dragging = false;
    const float max_drag = 100; 

    Ball::window = &window;
    Ball::W = window.getSize().x; 
    Ball::H = window.getSize().y; 
    Ball::friction = 0.9;

    LoadMap(1);

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }else if(event.type == sf::Event::MouseButtonPressed){
                mouse = sf::Mouse::getPosition(window);
                for(auto &i : Ball::balls){        // checking if hovered over ball
                    if(i.checkHover(mouse.x, mouse.y)){
                        dragging = true;
                        break;
                    }
                }
            }
            if(event.type == sf::Event::MouseButtonReleased){
                if(dragging){
                    // Ball::active_ball -> setSpeed( mouse.x - sf::Mouse::getPosition(window).x, mouse.y - sf::Mouse::getPosition(window).y);
                    Ball::active_ball -> setSpeed( (mouse.x - sf::Mouse::getPosition(window).x) / 3, (mouse.y - sf::Mouse::getPosition(window).y) / 3);
                    Ball::active_ball -> body.setFillColor(Ball::active_ball -> color);
                    dragging = false;
                }    
            }
        }

        window.clear(sf::Color(102, 102, 102));

        for(auto &i : Wall::walls){
            window.draw(i.body);
        }

        for(auto &i : Ball::balls){        // updating positions
            i.update();
            window.draw(i.body);
        }



        if(dragging && Ball::movable){      // Drawing guide for trail
            float distance = sqrt(pow(mouse.x - sf::Mouse::getPosition(window).x, 2) + pow(mouse.y - sf::Mouse::getPosition(window).y, 2));
            double angle = bnw::getEquationAngle((sf::Vector2f)mouse, (sf::Vector2f)sf::Mouse::getPosition(window));
            float x = cos(angle + M_PI_2) * Ball::active_ball -> body.getRadius() / 2;
            float y = sin(angle + M_PI_2) * Ball::active_ball -> body.getRadius() / 2;
 
            sf::Vertex trail[3];
                
            if(distance < 200){
                sf::Color trail_color((distance <= 100) ? (distance / 100 * 255) : (255), (distance >= 100) ? ((100 - distance) / 100 * 255) : (255), 0);
                
                trail[0] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x + x, Ball::active_ball -> getPos().y + y), trail_color);
                trail[1] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x - x, Ball::active_ball -> getPos().y - y), trail_color);
                trail[2] = sf::Vertex(sf::Vector2f(2 * (sf::Vector2i)Ball::active_ball -> getPos() - sf::Mouse::getPosition(window)), trail_color);
            
                Ball::active_ball -> body.setFillColor(trail_color);    
            }else{      // Pushing velocity cap
                trail[0] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x + x, Ball::active_ball -> getPos().y + y), sf::Color::Red);
                trail[1] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x - x, Ball::active_ball -> getPos().y - y), sf::Color::Red);
                float tip_x = cos(angle) * 200;
                float tip_y = sin(angle) * 200;
                
                std::cout << sf::Mouse::getPosition(window).x << " " << Ball::active_ball -> getPos().x <<" " << angle << " \r\n";

                if(sf::Mouse::getPosition(window).x < Ball::active_ball -> getPos().x +2.5){
                    trail[2] = sf::Vertex(sf::Vector2f( Ball::active_ball -> getPos().x + tip_x, Ball::active_ball -> getPos().y + tip_y), sf::Color::Red);
                }else{
                    trail[2] = sf::Vertex(sf::Vector2f( Ball::active_ball -> getPos().x - tip_x, Ball::active_ball -> getPos().y - tip_y), sf::Color::Red);  
                }

                Ball::active_ball -> body.setFillColor(sf::Color::Red);
            }

            window.draw(trail, 3, sf::Triangles);
            window.draw(Ball::active_ball -> body);       // might be optimizeable
        }

        window.display();

    }   

    return EXIT_SUCCESS;
}