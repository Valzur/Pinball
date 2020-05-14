#include "Flipper.h"

Flipper::Flipper(FlipperType type, Vector2D center, double length, double angle, double majorRadius, double minorRadius, double NormalAngle, double ExtendedAngle,double Velocity):
    type(type), center(center), length(length), angle(angle), majorRadius(majorRadius), minorRadius(minorRadius),NormalAngle(NormalAngle),ExtendedAngle(ExtendedAngle), Velocity(Velocity){}

Vector2D Flipper::collideWith(Ball & ball, double collision_time, Manager & manager)
{
    Vector2D Acceleration={0,0}, minorCenter;

    minorCenter=center+ Vector2D {cos(angle),sin(angle)}*length;

    Acceleration+=CircleCollision(ball,center,majorRadius,collision_time);
    Acceleration+=CircleCollision(ball,minorCenter,minorRadius,collision_time);

    return{0,0};
}

void Flipper::draw(Interface & interface)
{
    interface.drawFlipper(type, center, length, angle, majorRadius, minorRadius);
}

void Flipper::RotateFlipper(double a, double time){
    if(a>0){
        if(angle<0.7*a) {
            angle += time * Velocity;
            ImpulseMultiplier=1.5;
        }else if(angle>a/0.7){
            angle -= time * Velocity;
            ImpulseMultiplier=1.5;
        }else{
            angle=a;
            ImpulseMultiplier=1;
        }
    }else{
        if(angle<a/0.7) {
            angle += time * Velocity;
            ImpulseMultiplier=1.5;
        }else if(angle>a*0.7){
            angle -= time * Velocity;
            ImpulseMultiplier=1.5;
        }else{
            angle=a;
            ImpulseMultiplier=1;
        }
    }

}

void Flipper::MoveFlipper(bool left, bool right, double delta_time) {
    //A little finicky, but its cleaner :')
    switch(type) {
        //Left
        //If clicked
        case FlipperType(LEFT):
            if (left) {
                RotateFlipper(-ExtendedAngle, delta_time);
            } else {
                RotateFlipper(-NormalAngle, delta_time);
            }
            break;
        case FlipperType(RIGHT):
            if (right) {
                RotateFlipper(ExtendedAngle, delta_time);
            } else {
                RotateFlipper(NormalAngle, delta_time);
            }
            break;
    }
}
