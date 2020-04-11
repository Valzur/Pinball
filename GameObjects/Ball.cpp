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

void Ball::move(float time, Manager& manager,bool &lost){
    if(isActive) {
        manager.ValueUpdate(*this,lost);
        // Kinematic equations for planar motion of a particle
        velocity += Acceleration * time;
        center += velocity * time - Acceleration * time * time * 0.5;
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

Vector2D Ball::collideWith(Ball &ball, float collision_time, Manager & manager) {
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

bool Ball::getIsUsedPortal() const{
    return isUsedPortal;
}

void Ball::setUsedPortal(bool Used) {
    isUsedPortal=Used;
}

Vector2D Ball::getAcceleration() const {
    return  Acceleration;
}

void Ball::setAcceleration(Vector2D Acceleration) {
    this-> Acceleration=Acceleration;
}
