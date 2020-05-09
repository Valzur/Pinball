
#include "SpeedBooster.h"

void SpeedBooster::draw(Interface &interface) {
    interface.drawSpeedBooster(radius,Center);
}

Vector2D SpeedBooster::collideWith(Ball &ball, float collision_time, Manager &manager) {
    bool isInside=BICCollision(ball,Center,radius);

    if(isInside){
        ball.Boost(SpeedBoosterAmount);
    }
    return {0,0};
}

SpeedBooster::SpeedBooster(float radius, Vector2D Center): Center(Center) {
    this->radius=radius;
}
