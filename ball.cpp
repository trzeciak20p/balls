#include "ball.h"
// #include <iostream>


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


bool Ball::checkRange(float _x, float _y){
    float distance = sqrt( (_x-x)*(_x-x) + (_y-y)*(_y-y));
    if(distance <= body.getRadius()){
        Ball::active_ball = this;
        return true;
    }
    return false;
}

void Ball::setSpeed(float _x, float _y){
    if(movable){
        movable = false;
        vel_x = _x;
        vel_y = _y;
    }
}

void Ball::update(){
    if(vel_x == 0 && vel_y == 0)
        return;

    if(x + vel_x < body.getRadius() || x + vel_x >= Ball::window -> getSize().x - body.getRadius())        //changing directions
        vel_x *= -1;
    if(y + vel_y < body.getRadius() || y + vel_y >= Ball::window -> getSize().y - body.getRadius())
        vel_y *= -1;

    x += vel_x;
    y += vel_y; 

    body.setPosition(sf::Vector2f(x, y));

    vel_x *= Ball::friction;      // lowering speed
    vel_y *= Ball::friction;

    if( (vel_x < 1 && vel_x > -1) || (vel_y < 1 && vel_y > -1)){
        vel_x = vel_y = 0;      // clearing both so the ball doesn't move unnaturally in one direction after some time
        Ball::movable = true;
    }

}
