#include "Ball.h"

Ball::Ball(Vector2D center, Vector2D velocity): center(center), velocity(velocity) {}

float Ball::getRadius() const
{
    return radius;
}

Vector2D Ball::getCenter() const
{
    return center;
}

Vector2D Ball::getVelocity() const
{
    return velocity;
}

void Ball::move(Vector2D acceleration, float time)
{
    // Kinematic equations for planar motion of a particle
    velocity += acceleration * time;
    center += velocity * time - acceleration * time * time * 0.5;
}

void Ball::draw (Interface & interface)
{
    interface.drawBall(center, radius);
}
