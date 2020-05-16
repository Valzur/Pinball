#include "Flipper.h"

Flipper::Flipper(FlipperType type, Vector2D center, double length, double angle, double majorRadius, double minorRadius, double NormalAngle, double ExtendedAngle,double Velocity):
    type(type), center(center), length(length), angle(angle), majorRadius(majorRadius), minorRadius(minorRadius),NormalAngle(NormalAngle),ExtendedAngle(ExtendedAngle), Velocity(Velocity){
    if(buffer.loadFromFile("../Assets/SFX/Flipper.wav")){
        sound.setBuffer(buffer);
    }else{
        std:: cout << "Unable to load Flipper.wav!" << std::endl;
    }
}

Vector2D Flipper::collideWith(Ball & ball, double collision_time, Manager & manager)
{
    Vector2D velocity={0,0}, Direction;
    Direction =  Vector2D {cos(angle*180/PI),sin(angle*180/PI)}*length;

    velocity = RectangleCollision(ball,length,minorRadius,angle,center);
    if(velocity != Vector2D{0,0}){
        ball.setVelocity(velocity*-ImpulseMultiplier);
    }
    return {0,0};
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
    if(!Left & left){
        sound.play();
    }
    if(!Right & right){
        sound.play();
    }

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
    Left = left;
    Right = right;
}
