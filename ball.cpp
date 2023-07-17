#include "ball.h"

#include <iostream>
#include "src/utils/utils_2d.cpp"


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
        float angle, angle2;
        angle = bnw::getEquationAngle(getPos(), sf::Vector2f(new_x, new_y));
        

        // Cheking for corners
        if(float distance = getDistacne(wall.getLeft() - vel_x, wall.getTop() - vel_y) <= body.getRadius() ){
            // angle2 = bnw::getEquationAngle(getPos(), sf::Vector2f(wall.getLeft(), wall.getTop()) );
            // float relative_x = wall.getLeft() - x;
            // float relative_y = wall.getTop() - y;
            // x = wall.getLeft() - wall.getTop() + y;
            // y = wall.getTop() - wall.getLeft() + x;
            // angle = atan(1);
            
            

            if(angle < 0){
                if(x > y){                    // Determining which side is ball comming from
                    // right
                    x = wall.getLeft() + cos(M_PI + M_PI_4 + angle) * (distance*10 + body.getRadius());
                    y = wall.getTop() - sin(M_PI + M_PI_4 + angle) * (distance*10 + body.getRadius());
                }else{
                    // left
                    x = wall.getLeft() + cos(angle - M_PI_4) * (distance*10 + body.getRadius());
                    y = wall.getTop() - sin(angle - M_PI_4) * (distance*10 + body.getRadius());
                }
            }else{
                x = wall.getLeft() + cos(M_PI_2 + angle) * (distance*10 + body.getRadius());
                y = wall.getTop() - sin(M_PI_2 + angle) * (distance*10 + body.getRadius());
                float vel_x_buffer = vel_x;
                vel_x = -vel_y;
                vel_y = -vel_x_buffer;
                decrease_vel_x *= -1;
                decrease_vel_y *= -1;
                // float x_buffer = x;
                // x = wall.getLeft() - wall.getTop() + y;
                // y = wall.getTop() - wall.getLeft() + x;
            }


            // if(x > y){        // right side
            //     std::cout << "right\r\n";
            //     if(angle < 0){
            //         x = wall.getLeft() + cos(M_PI_2 - angle) * (distance*10 + body.getRadius());
            //         y = wall.getTop() - sin(M_PI_2 - angle) * (distance*10 + body.getRadius());
            //     }else{
            //         x = wall.getLeft() + cos(M_PI + M_PI_4 - angle) * (distance*10 + body.getRadius());
            //         y = wall.getTop() - sin(M_PI + M_PI_4 - angle) * (distance*10 + body.getRadius());
            //     }

            // }else{      // left side
            //     std::cout << "left\r\n";

            //     if(angle < 0){
            //         x = wall.getLeft() + cos(M_PI_2  - angle) * (distance*10 + body.getRadius());
            //         y = wall.getTop() - sin(M_PI_2 - angle) * (distance*10 + body.getRadius());
            //     }else{
            //         x = wall.getLeft() + cos(M_PI + M_PI_4 + angle) * (distance*10 + body.getRadius());
            //         y = wall.getTop() - sin(M_PI + M_PI_4 + angle) * (distance*10 + body.getRadius());
            //     }

            // }


            // if(angle < 0){
            //     x = wall.getLeft() + cos(M_PI_2 + M_PI_4 + angle) * (distance*10 + body.getRadius());
            //     y = wall.getTop() - sin(M_PI_2 + M_PI_4 + angle) * (distance*10 + body.getRadius());
            // }else{
            //     x = wall.getLeft() + cos(M_PI_2 + M_PI_4 - angle) * (distance*10 + body.getRadius());
            //     y = wall.getTop() - sin(M_PI_2 + M_PI_4 - angle) * (distance*10 + body.getRadius());
            // }
            
            // if(x == 0 && y == 0){
            //     x = wall.getLeft() + cos(M_PI_2 + M_PI_4) * (distance*10 + body.getRadius());
            //     y = wall.getTop() - sin(M_PI_2 + M_PI_4) * (distance*10 + body.getRadius());
            // }
            
            std::cout << "diff x: " << x - wall.getLeft() << "diff y: " << y - wall.getTop() << "\r\n";


        }else if( getDistacne(wall.getLeft() - vel_x, wall.getBottom() - vel_y) <= body.getRadius() ){


        }else if( getDistacne(wall.getRight() - vel_x, wall.getTop() - vel_y) <= body.getRadius() ){


        }else if( getDistacne(wall.getRight() - vel_x, wall.getBottom() - vel_y) <= body.getRadius() ){

        }else{

            // Checking for sides
            if( (new_x + body.getRadius() > wall.getLeft() || new_x - body.getRadius() > wall.getRight()) && (new_y >= wall.getTop() && new_y <= wall.getBottom()) ){
                vel_x *= -1;
                decrease_vel_x *= -1;
            }
            if( (new_y + body.getRadius() > wall.getTop() || new_y - body.getRadius()  > wall.getBottom()) && (new_x >= wall.getLeft() && new_x <= wall.getRight()) ){
                vel_y *= -1;
                decrease_vel_y *= -1;
            }
            return;
        }


        std::cout << "angle: " << atan(angle) << "\tangle2: " << atan(angle2) << "\r\n"; 
        // std::cout << x << "\t" << y << "\r\n"; 
        
        
        // vel_x = vel_y = 0;
        
        


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
            // uwzględnić prędkość obu piłek



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