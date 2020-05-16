#include"ThrustBumper.h"

ThrustBumper::ThrustBumper(Vector2D pos, double rad) : Bumper(pos, rad, BumperType::THRUST) {
    if(buffer.loadFromFile("../Assets/SFX/Thrust.wav")){
        sound.setBuffer(buffer);
    }else{
        std:: cout << "Unable to load Thrust.wav!" << std::endl;
    }
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
        if(AllowHit){
            ball.setVelocity(Acceleration*ThrustBumperBoost/collision_time);
            sound.play();
            manager.addScore(750);
            AllowHit=false;
        }
    }
    return {0,0};
}
