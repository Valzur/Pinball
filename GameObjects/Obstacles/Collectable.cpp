#include "Collectable.h"

Collectable::Collectable(double radius, string L,Vector2D Center): Center(Center) {
    this->radius=radius;
    this->L=L;

}

void Collectable::draw(Interface &interface)
{
    if(Active)
        interface.drawCollectable(radius,L,Center,Used);
}

Vector2D Collectable::collideWith(Ball &ball, double collision_time, Manager &manager)
{
    if(Used){
        if(Timer>0){
            Timer-=collision_time;
        } else {
            Active=false;
        }

    } else {
        if(BICCollision(ball,Center,radius)){
            Used=true;
        }
    }
    return {0,0};
}
