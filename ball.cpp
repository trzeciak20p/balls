#include "ball.h"


Ball::Ball(float _x, float _y, float _size, sf::Color _color) : x{_x + _size}, y{_y + _size}, color{_color}{
    vel_x = vel_y = 0.0f;

    body.setPosition(x, y);
    body.setRadius(_size);
    body.setFillColor(_color);
    body.setOrigin(sf::Vector2f(_size, _size));
}

Ball::~Ball(){
    //jakby tu walnąć particle explosion byłoby cool
}

sf::Vector2f Ball::getPos(){
    return sf::Vector2f(x, y);
}

int Ball::getx(){
    return x;
}
int Ball::gety(){
    return y;
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
    vel_x = _x;
    vel_y = _y;
}

void Ball::update(){
    if(vel_x == 0 && vel_y == 0)
        return;

    if(x + vel_x < 0 || x + vel_x >= (*Ball::window).getSize().x)        //changing directions
        vel_x *= 1;
    if(y + vel_y < 0 || y + vel_y >= (*Ball::window).getSize().y)
        vel_y *= 1;
            
    x += vel_x;
    y += vel_y; 

    body.setPosition(sf::Vector2f(x, y));

    vel_x -= friction;      // lowering speed
    if(vel_x < 0)
        vel_x = 0;
    vel_y -= friction;
    if(vel_y < 0)
        vel_y = 0;

    if(vel_x && vel_y)
        Ball::movable = false;
}
