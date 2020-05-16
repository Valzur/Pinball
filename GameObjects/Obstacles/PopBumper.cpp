#include "PopBumper.h"

PopBumper::PopBumper(Vector2D pos, double rad) : Bumper(pos, rad,POP) {
    if(buffer.loadFromFile("../Assets/SFX/Bumper.wav")){
        sound.setBuffer(buffer);
    }else{
        std:: cout << "Unable to load Bumper.wav!" << std::endl;
    }
}

void PopBumper::draw(Interface &interface) {
    interface.drawPopBumper(GetPosition(),GetRadius(),Hit);
}

Vector2D PopBumper::collideWith(Ball &ball, double collision_time, Manager &manager) {
    Vector2D Acceleration={0,0};
    if(AllowHit)
        Acceleration = CircleCollision(ball,GetPosition(),GetRadius(),collision_time);

    if(Acceleration==Vector2D{0,0}){
        AllowHit = true;
    }else{
        ball.setVelocity(Acceleration*collision_time);
        Hit = true;
        AllowHit = false;
    }

    if(Hit &(hitTimer>0))
        hitTimer-=collision_time;
    else {
        if(hitTimer<=0){
            manager.addScore(400);
            sound.play();
        }

        hitTimer=FlashTimer;
        Hit=false;
    }
    return {0,0};
}
