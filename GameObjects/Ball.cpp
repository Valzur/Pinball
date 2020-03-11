#include "Ball.h"

Ball::Ball(Vector2D center, Vector2D velocity): center(center), velocity(velocity) {
    isActive=false;
}

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
{   if(isActive) {
        // Kinematic equations for planar motion of a particle
        velocity += acceleration * time;
        center += velocity * time - acceleration * time * time * 0.5;
    }
}

void Ball::draw (Interface & interface)
{
    interface.drawBall(center, radius);
}

void Ball::setCenter(Vector2D pos) {
    center=pos;
}

void Ball::setVelocity(Vector2D vel) {
    velocity=vel;
}
<<<<<<< HEAD
=======

void Ball::Activate() {
    isActive=true;
}

void Ball::deActivate() {
    isActive=false;
}
>>>>>>> master
