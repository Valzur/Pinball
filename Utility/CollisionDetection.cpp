#include "CollisionDetection.h"

Vector2D CircleCollision(const Ball& ball,Vector2D position, double radius, double collision_time) {
    Vector2D Acceleration = {0, 0},Velocity;
    double ScalarVelocity=VectorNorm(ball.getVelocity());
    if (VectorDistance(ball.getCenter(), position) < radius + ball.getRadius()) {
        Velocity=ball.getVelocity()-((ball.getVelocity())*(ball.getCenter()-position))/pow(VectorNorm(position - ball.getCenter()),2)*(ball.getCenter()-position);
        Velocity=Velocity/VectorNorm(Velocity);
        Acceleration=(Velocity)*ScalarVelocity/collision_time;
    }
    return Acceleration;
}

bool BICCollision(Ball &ball, Vector2D position, double radius) {
    bool detected = false;
    if (VectorDistance(ball.getCenter(), position) < radius - ball.getRadius())
        detected = true;

    return detected;
}
