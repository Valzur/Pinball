//
// Created by anon on 4/11/20.
//

#include "SpeedBooster.h"

void SpeedBooster::draw(Interface &interface) {
    interface.drawSpeedBooster(radius);

}

Vector2D SpeedBooster::collideWith(Ball &ball, float collision_time, Manager &manager) {
    return {0,0};
}

SpeedBooster::SpeedBooster(float radius) {
    this->radius=radius;

}
