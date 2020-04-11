#include"ThurstBumper.h"

ThurstBumper::ThurstBumper(Vector2D pos, float rad) : Bumper(pos, rad, BumperType::THRUST) {
    setScorepoints(50);
}

void ThurstBumper::draw(Interface& interface) {
    Bumper::draw(interface);
}

Vector2D ThurstBumper::collideWith(Ball& ball, float collision_time, Manager& manager) {
    return Bumper::collideWith(ball, collision_time, manager);
}
