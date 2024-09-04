#ifndef BOUNCE_GAME
#define BOUNCE_GAME

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>

#include "mapLoader.h"
#include "ball.h"
#include "wall.h"
#include "../utils/utils_2d.h"


class Game{

    public:
        enum class State{
            paused = 0,
            playing,
            menu,
            settings,
            map_selection
        };

    private:
        sf::Window *window;
        State state;

    public:
        bool dragging = false;
        sf::Vector2i mouse;
        sf::Vertex trail[3];


        Game(sf::Window *window);
        ~Game();

        State getState();

        void errorReport(std::string err);
        bool calculateTrail();     // Calculates trail for drawing


        void mousePress();
        void mouseRelease();


};


inline bool Game::calculateTrail(){
    if(!(dragging && Ball::movable))
        return false;
    
        float distance = sqrt(pow(mouse.x - sf::Mouse::getPosition(*window).x, 2) + pow(mouse.y - sf::Mouse::getPosition(*window).y, 2));
        double angle = bnw::getEquationAngle((sf::Vector2f)mouse, (sf::Vector2f)sf::Mouse::getPosition(*window));
        float x = cos(angle + M_PI_2) * Ball::active_ball -> body.getRadius() / 2;
        float y = sin(angle + M_PI_2) * Ball::active_ball -> body.getRadius() / 2;


        if(distance < 200){
            sf::Color trail_color((distance <= 100) ? (distance / 100 * 255) : (255), (distance >= 100) ? ((100 - distance) / 100 * 255) : (255), 0);
            
            trail[0] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x + x, Ball::active_ball -> getPos().y + y), trail_color);
            trail[1] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x - x, Ball::active_ball -> getPos().y - y), trail_color);
            trail[2] = sf::Vertex(sf::Vector2f(2 * (sf::Vector2i)Ball::active_ball -> getPos() - sf::Mouse::getPosition(*window)), trail_color);

            Ball::active_ball -> body.setFillColor(trail_color);    
        }else{      // speed velocity cap
            trail[0] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x + x, Ball::active_ball -> getPos().y + y), sf::Color::Red);
            trail[1] = sf::Vertex(sf::Vector2f(Ball::active_ball -> getPos().x - x, Ball::active_ball -> getPos().y - y), sf::Color::Red);
            float tip_x = cos(angle) * 200;
            float tip_y = sin(angle) * 200;

            std::cout << sf::Mouse::getPosition(*window).x << " " << Ball::active_ball -> getPos().x <<" " << angle << " \r\n";

            if(sf::Mouse::getPosition(*window).x < Ball::active_ball -> getPos().x +2.5){
                trail[2] = sf::Vertex(sf::Vector2f( Ball::active_ball -> getPos().x + tip_x, Ball::active_ball -> getPos().y + tip_y), sf::Color::Red);
            }else{
                trail[2] = sf::Vertex(sf::Vector2f( Ball::active_ball -> getPos().x - tip_x, Ball::active_ball -> getPos().y - tip_y), sf::Color::Red);  
            }
            Ball::active_ball -> body.setFillColor(sf::Color::Red);
        }
    return true;
}

inline void Game::mousePress(){
    switch(state){
        case Game::State::menu:



            break;

        case Game::State::map_selection:



            break;

        case Game::State::settings:



           break;

        case Game::State::playing:
            mouse = sf::Mouse::getPosition(*window);
            for(auto &i : Ball::balls){        // checking if hovered over ball
                if(i.checkHover(mouse.x, mouse.y)){
                    dragging = true;
                    break;
                }
            }

            break;
        case Game::State::paused:

            break;
        default:
            errorReport("MOSUE CLICK SWITCH ERROR");
        break;
    }


}

inline void Game::mouseRelease(){
switch(state){
        case Game::State::menu:



            break;

        case Game::State::map_selection:



            break;

        case Game::State::settings:



           break;

        case Game::State::playing:
            if(dragging){
                // Ball::active_ball -> setSpeed( mouse.x - sf::Mouse::getPosition(window).x, mouse.y - sf::Mouse::getPosition(window).y);
                Ball::active_ball -> setSpeed( (mouse.x - sf::Mouse::getPosition(*window).x) / 3, (mouse.y - sf::Mouse::getPosition(*window).y) / 3);
                Ball::active_ball -> body.setFillColor(Ball::active_ball -> color);
                dragging = false;   
            }
            break;
        case Game::State::paused:

            break;
        default:
            errorReport("MOSUE CLICK SWITCH ERROR");
        break;
    }


}







#endif //BOUNCE_GAME