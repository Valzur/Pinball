#include "CollisionDetection.h"

Vector2D CircleCollision(const Ball& ball,Vector2D position, double radius, double collision_time) {
    Vector2D Acceleration = {0, 0};
    if (VectorDistance(ball.getCenter(), position) < radius + ball.getRadius()) {

    }
    return Acceleration;
}

    bool BICCollision(const Ball &ball, Vector2D position, double radius) {
        bool detected = false;
        if (VectorDistance(ball.getCenter(), position) < radius - ball.getRadius())
            detected = true;

        return detected;
    }
