#include "Ball.h"

Ball::Ball(Vector2D center,float radius, Vector2D velocity,bool Main): InitialPosition(center), velocity(velocity),InitialVelocity(velocity),radius(radius) {
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

void Ball::Activate(bool & space) {
    if(space & isMain)
        isActive=true;
}

void Ball::deActivate() {
    isActive=false;
}

Vector2D Ball::BallToBallCollision(const Ball& ball) {
    if(ball.getCenter().x==center.x & ball.getCenter().y == center.y){
        return {0,0};
    }else {
        Vector2D acc = {0, 0};
        Vector2D dir;
        if (VectorDistance(ball.getCenter(), center) <= radius + ball.getRadius()) {
            //Break Captivity
            if (!isMain & !isActive)
                isActive=true;

            //Readjust balls
            dir = VectorDirection(center, ball.getCenter());
            setCenter(center + dir * VectorNorm(center - ball.getCenter()));
            //Acceleration measurement
            acc = ball.getVelocity();
        }
        return acc;
    }
}

void Ball::Reset() {
    deActivate();
    setCenter(InitialPosition);
    setVelocity(InitialVelocity);
}

bool Ball::getisMain() const {
    return isMain;
}
