#include "Flipper.h"

Flipper::Flipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius):
    type(type), center(center), length(length), angle(angle), majorRadius(majorRadius), minorRadius(minorRadius) {}

Vector2D Flipper::collideWith(Ball & ball, float collision_time)
{
    Vector2D acc={ImpulseMultiplier,ImpulseMultiplier};

    return acc;
}

void Flipper::draw(Interface & interface)
{
    interface.drawFlipper(type, center, length, angle, majorRadius, minorRadius);
}

void Flipper::RotateFlipper(float a, float time){
    if(a>0){
        if(angle<0.7*a) {
            angle += time * FLIPPERS_ROTATE_VELOCITY;
            ImpulseMultiplier=1.5;
        }else if(angle>a/0.7){
            angle -= time * FLIPPERS_ROTATE_VELOCITY;
            ImpulseMultiplier=1.5;
        }else{
            angle=a;
            ImpulseMultiplier=1;
        }
    }else{
        if(angle<a/0.7) {
            angle += time * FLIPPERS_ROTATE_VELOCITY;
            ImpulseMultiplier=1.5;
        }else if(angle>a*0.7){
            angle -= time * FLIPPERS_ROTATE_VELOCITY;
            ImpulseMultiplier=1.5;
        }else{
            angle=a;
            ImpulseMultiplier=1;
        }
    }

}
