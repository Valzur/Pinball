
#include "SpeedBooster.h"

void SpeedBooster::draw(Interface &interface) {
    interface.drawSpeedBooster(radius,Center,Hit);
}

Vector2D SpeedBooster::collideWith(Ball &ball, double collision_time, Manager &manager) {
    bool isInside = BICCollision(ball,Center,radius);

    if(isInside){
        ball.Boost(SpeedBoosterAmount);
        Hit = true;
        HitTimer=FlashTimer;
    }
    if( (HitTimer>0) & Hit ){
        HitTimer-=collision_time;
    }else{
        Hit = false;
    }
    return {0,0};
}

SpeedBooster::SpeedBooster(double radius, Vector2D Center): Center(Center) {
    this->radius=radius;
}
