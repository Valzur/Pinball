#include "Ball.h"

Ball::Ball(Vector2D center, Vector2D velocity,bool Main): InitialPosition(center), velocity(velocity) {
    isActive=false;
    isMain=Main;
    setCenter(InitialPosition);
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

void Ball::Activate() {
    isActive=true;
}

void Ball::deActivate() {
    isActive=false;
}

Vector2D Ball::BallToBallCollision(Ball ball) {
    Vector2D acc={0,0};
    Vector2D dir;
    if(VectorDistance(ball.getCenter(),center)<=radius+ball.getRadius()){
        //Break Captivity
        if(!isMain & !isActive)
            Activate();

        //Readjust balls
        dir=VectorDirection(center,ball.getCenter());
        setCenter(center+dir*VectorNorm(center - ball.getCenter()));
        //Acceleration measurement
        acc=ball.getVelocity();
    }
    return acc;
}

void Ball::Reset() {
    deActivate();
    setCenter(InitialPosition);
    setVelocity(INITIAL_VELOCITY);
}
