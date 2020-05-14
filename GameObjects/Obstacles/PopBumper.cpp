#include "PopBumper.h"

PopBumper::PopBumper(Vector2D pos, double rad) : Bumper(pos, rad,POP) {}

void PopBumper::draw(Interface &interface) {
    Bumper::draw(interface);
}

Vector2D PopBumper::collideWith(Ball &ball, double collision_time, Manager &manager) {
    Vector2D Acceleration={0,0};
    Acceleration=CircleCollision(ball,GetPosition(),GetRadius(),collision_time);
    return Acceleration;
}
