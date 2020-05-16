#include "VibraniumBumper.h"

VibraniumBumper:: VibraniumBumper(Vector2D pos, double rad): Bumper(pos,rad,  VIBRANIUM){
    setScorepoints(0);
}
void VibraniumBumper::draw(Interface& interface) {
    interface.drawVibraniumBumper(GetPosition(), GetRadius(),Hit);
}

Vector2D VibraniumBumper::collideWith(Ball& ball, double collision_time, Manager& manager) {
    Vector2D Acceleration={0,0};
    if (ball.getRadius() + GetRadius() >= VectorDistance(ball.getCenter(), GetPosition())) {
        Acceleration = { 0,9800 };
        ball.setVelocity({ 0,0 });
        manager.addScore(-50);
    }

    return Acceleration;
}

