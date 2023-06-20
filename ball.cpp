#include "ball.h"
#include <iostream>


Ball::Ball(float _x, float _y, float _size, sf::Color _color) : x{_x + _size}, y{_y + _size}, color{_color}{
    vel_x = vel_y = 0.0f;

    body.setPosition(x, y);
    body.setRadius(_size);
    body.setFillColor(_color);
    body.setOrigin(sf::Vector2f(_size, _size));
    balls.push_back(*this);
}

Ball::~Ball(){
    // make some exsplosion effect
}

sf::Vector2f Ball::getPos(){
    return sf::Vector2f(x, y);
}

float Ball::getDistacne(float _x, float _y){
    return sqrt( (_x-x)*(_x-x) + (_y-y)*(_y-y));
}

void Ball::checkBounce(){
    for(auto &wall : Wall::walls){
        float new_x = x + vel_x, new_y = y + vel_y;

        if( (new_x + body.getRadius() > wall.getLeft() || new_x - body.getRadius() > wall.getRight()) && (new_y >= wall.getTop() && new_y <= wall.getBottom()) ){
            vel_x *= -1;
            decrease_vel_x *= -1;

        }
        if( (new_y + body.getRadius() > wall.getTop() || new_y - body.getRadius()  > wall.getBottom()) && (new_x >= wall.getLeft() && new_x <= wall.getRight()) ){
            vel_y *= -1;
            decrease_vel_y *= -1;
        }

        if( getDistacne(wall.getLeft() - vel_x, wall.getTop() - vel_y) <= body.getRadius()){
            vel_x *= -1;
            decrease_vel_x *= -1;
            vel_y *= -1;
            decrease_vel_y *= -1;
        }
        


        // if(x + vel_x < body.getRadius() + wall.getLeft() || x + vel_x >= Ball::window -> getSize().x - body.getRadius() + wall.getRight()){       //changing directions
        //     vel_x *= -1;
        //     decrease_vel_x *= -1;
        // }
        // if(y + vel_y < body.getRadius() + wall.getBottom() || y + vel_y >= Ball::window -> getSize().y - body.getRadius() + wall.getTop()){
        //     vel_y *= -1;
        //     decrease_vel_y *= -1;
        // }


    }

    for(auto &i : Ball::balls){




    }


}



bool Ball::checkHover(float _x, float _y){      // Checks if cursor hovers over ball     
    if(getDistacne(_x, _y) <= body.getRadius()){
        Ball::active_ball = this;
        return true;
    }
    return false;
}

void Ball::setSpeed(float _x, float _y){
    if(movable){
        movable = false;
        vel_x = _x/2;
        vel_y = _y/2;
        decrease_vel_x = _x / Ball::friction;
        decrease_vel_y = _y / Ball::friction;
    }
}

void Ball::update(){
    if(vel_x == 0 && vel_y == 0)
        return;

    if(x + vel_x < body.getRadius() || x + vel_x >= Ball::window -> getSize().x - body.getRadius()){       // changing directions from boundaries
        vel_x *= -1;
        decrease_vel_x *= -1;
    }
    if(y + vel_y < body.getRadius() || y + vel_y >= Ball::window -> getSize().y - body.getRadius()){
        vel_y *= -1;
        decrease_vel_y *= -1;
    }

    checkBounce();


    x += vel_x;
    y += vel_y; 

    body.setPosition(sf::Vector2f(x, y));

    vel_x *= Ball::friction;      // lowering speed
    vel_y *= Ball::friction;

    if((vel_x < 0.2 && vel_x > -0.2) && (vel_y < 0.2 && vel_y > -0.2)){
        vel_x = vel_y = 0;
        Ball::movable = true;
    }

}