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

Vector2D Lcollision(const Ball& ball, Vector2D Position, double L, double W, double collision_time) {
    Vector2D Acceleration = { 0,0 }, v;
    bool isbetween = InRange(ball.getCenter().x, Position.x + L/2, Position.x-L/2);
    if (isbetween && abs(ball.getCenter().y - Position.y) <= ball.getRadius()+W/2) {
        Acceleration = { ball.getVelocity().x * -2,ball.getVelocity().y * -2 };
        Acceleration = Acceleration / collision_time;
    }
    return Acceleration;

}
bool InRange(double value, double max, double min)
{
    return value >= min && value <= max;
}