#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <math.h>
#include <iostream>

#include "ball.h"
// #include "wall.h"

// nawalasz się kulami na zmiane, jak twoja kulka walnie w czerwoną ściane 3 razy to umierasz
// system hp i robisz craki w kulkach 

struct Equation{
    double a;
    double b;
    double ang;
    int getX(float y){
        return (y - b) / a;
    };
    int getY(float x){
        return a * x + b;
    }
};

Equation getEquation(sf::Vector2f A, sf::Vector2f B){
    double a = (B.y - A.y) / (B.x - A.x);
    double b = ((B.x*A.y) - (A.x*B.y)) / B.x - A.x;
    double ang = atan(a);
    return Equation{a, b, ang};
} 


int main(){

    // Window szouldn't be resizeable as it interferes with checking positions
    sf::RenderWindow window(sf::VideoMode(800, 700), "Balls", sf::Style::Close);        
    window.setFramerateLimit(60);

    sf::Vector2i mouse;

    bool dragging = false;
    const float max_drag = 100; 

    Ball::window = &window;
    Ball::W = window.getSize().x; 
    Ball::H = window.getSize().y; 
    Ball::friction = 0.9;

    Ball(100, 100);
    Ball(700, 600, 20, sf::Color::Black);

    Wall(600, 600, 200, 100);

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
                    Ball::active_ball -> setSpeed( mouse.x - sf::Mouse::getPosition(window).x, mouse.y - sf::Mouse::getPosition(window).y);
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



        if(dragging && Ball::movable){
            // mouse_dif = sf::Mouse::getPosition(window) - mouse;
            float distance = sqrt(pow(mouse.x - sf::Mouse::getPosition(window).x, 2) + pow(mouse.y - sf::Mouse::getPosition(window).y, 2));
            // std::cout << distance << "\r\n";
            //zmienić potem na to że bierze środek wybranego kółka
            Equation line_guide_equ = getEquation((sf::Vector2f)mouse, (sf::Vector2f)sf::Mouse::getPosition(window));       // geting equation from dragged line 

            float x = cos(line_guide_equ.ang + (M_PI_2)) * Ball::active_ball -> body.getRadius();
            float y = sin(line_guide_equ.ang + (M_PI_2)) * Ball::active_ball -> body.getRadius();
 

            // ograniczenie dla odległości zrobić
            // wziąć kąt z funkcji r zrobić max odległość i obrócić o 180 stopni (kursor)

            sf::Vertex line_guide[3];

            if(distance < 200){
                sf::Color line_guide_color((distance <= 100) ? (distance / 100 * 255) : (255), (distance >= 100) ? ((100 - distance) / 100 * 255) : (255), 0);
                
                line_guide[0] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x + x, Ball::active_ball -> getPos().y + y), line_guide_color);
                line_guide[1] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x - x, Ball::active_ball -> getPos().y - y), line_guide_color);
                line_guide[2] = sf::Vertex(sf::Vector2f(2 * (sf::Vector2i)Ball::active_ball -> getPos() - sf::Mouse::getPosition(window)), line_guide_color);
            

                Ball::active_ball -> body.setFillColor(line_guide_color);
                
            }else{      // pushing velocity cap
                // distance = 200;
                line_guide[0] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x + x, Ball::active_ball -> getPos().y + y), sf::Color::Red);
                line_guide[1] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x - x, Ball::active_ball -> getPos().y - y), sf::Color::Red);
                float tip_x = cos(line_guide_equ.ang) * 200;
                float tip_y = sin(line_guide_equ.ang) * 200;
                
                std::cout << sf::Mouse::getPosition(window).x << " " << Ball::active_ball -> getPos().x <<" \r\n";
                if(sf::Mouse::getPosition(window).x >= Ball::active_ball -> getPos().x){
                    tip_x *= -1;
                }
                if(sf::Mouse::getPosition(window).x > Ball::active_ball -> getPos().x){
                    tip_y *= -1;
                }
                std::cout << tip_x << " " << tip_y << " \r\n";

                
                line_guide[2] = sf::Vertex(sf::Vector2f( Ball::active_ball -> getPos().x + tip_x, Ball::active_ball -> getPos().y + tip_y), sf::Color::Red);


                Ball::active_ball -> body.setFillColor(sf::Color::Red);
            }


            

            window.draw(line_guide, 3, sf::Triangles);
            window.draw(Ball::active_ball -> body);       // might be optimizeable
        }

        window.display();

    }   

    return EXIT_SUCCESS;
}