#include"ThrustBumper.h"

ThrustBumper::ThrustBumper(Vector2D pos, double rad) : Bumper(pos, rad, BumperType::THRUST) {
    setScorepoints(150);
}

void ThrustBumper::draw(Interface& interface) {
    interface.drawThrustBumper(GetPosition(), GetRadius(),Hit);
}

Vector2D ThrustBumper::collideWith(Ball& ball, double collision_time, Manager& manager) {
    Vector2D Acceleration = { 0,0 };
    Acceleration = CircleCollision(ball, GetPosition(), GetRadius(), collision_time);
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
        manager.addScore(150);
        if(AllowHit){
            manager.addScore(150);
            AllowHit=false;
        }
    }
    return Acceleration;
}
