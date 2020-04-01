#include "PopBumper.h"

PopBumper::PopBumper(Vector2D pos, float rad) : Bumper(pos, rad) {

}

void PopBumper::draw(Interface &interface) {
    Bumper::draw(interface);
}

Vector2D PopBumper::collideWith(Ball &ball, float collision_time, Manager &manager) {
    Bumper::collideWith(ball, collision_time, manager);
}
