#include "Ramp.h"

Ramp::Ramp(Vector2D Center): Center(Center) {}

void Ramp::draw(Interface &interface) {
    interface.drawRamp(Center);
}

Vector2D Ramp::collideWith(Ball &ball, float collision_time, Manager &manager) {


    return {0,0};
}
