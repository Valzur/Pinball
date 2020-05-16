#include "PopBumper.h"

PopBumper::PopBumper(Vector2D pos, double rad) : Bumper(pos, rad,POP) {}

void PopBumper::draw(Interface &interface) {
    interface.drawPopBumper(GetPosition(),GetRadius(),Hit);
}

Vector2D PopBumper::collideWith(Ball &ball, double collision_time, Manager &manager) {
    Vector2D Acceleration={0,0};
    Acceleration=CircleCollision(ball,GetPosition(),GetRadius(),collision_time);
    if(Acceleration==Vector2D{0,0}){
        if(Hit &(hitTimer>0))
            hitTimer-=collision_time;
        else {
            hitTimer=FlashTimer;
            Hit=false;
            AllowHit=true;
        }
    }else{
        Hit=true;
        if(AllowHit){
            manager.addScore(150);
            AllowHit=false;
        }
    }
    return Acceleration;
}
