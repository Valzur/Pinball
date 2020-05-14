#include "VibraniumBumper.h"

VibraniumBumper:: VibraniumBumper(Vector2D pos, double rad): Bumper(pos,rad,  VIBRANIUM){
    setScorepoints(0);
}
void VibraniumBumper::draw(Interface& interface) {
    Bumper::draw(interface);
}

Vector2D VibraniumBumper::collideWith(Ball& ball, double collision_time, Manager& manager) {
    return {0,0};
}

