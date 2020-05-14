#include"ThrustBumper.h"

ThrustBumper::ThrustBumper(Vector2D pos, double rad) : Bumper(pos, rad, BumperType::THRUST) {
    setScorepoints(50);
}

void ThrustBumper::draw(Interface& interface) {
    Bumper::draw(interface);
}

Vector2D ThrustBumper::collideWith(Ball& ball, double collision_time, Manager& manager) {
    return Bumper::collideWith(ball, collision_time, manager);
}
