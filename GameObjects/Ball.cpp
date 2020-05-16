#include "Ball.h"

Ball::Ball(Vector2D center,float radius, Vector2D velocity,bool Main): InitialPosition(center), velocity(velocity),InitialVelocity(velocity),radius(radius) {
    isActive=false;
    isMain=Main;
    setCenter(InitialPosition);
    if(!Main){
        if(buffer.loadFromFile("../Assets/SFX/Captive.wav")){
            sound.setBuffer(buffer);
        }else{
            std:: cout << "Unable to load Captive.wav!" << std::endl;
        }
    }
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

void Ball::move(double time, Manager& manager,bool &lost){
    if(isActive){
        if(!isUsedLane) {
            manager.ValueUpdate(*this,lost);
            // Kinematic equations for planar motion of a particle
            setVelocity(velocity + Acceleration * time );
            setCenter( center + velocity *SpeedBoost* time + Acceleration * time * time * 0.5 );
        } else {
            if(isDirectedUp){
                if(LaneLength>0){
                    velocity=Vector2D{0,-1}*VectorNorm(velocity);
                    center+=velocity*time*SpeedBoost;
                    LaneLength-=VectorNorm(velocity)*time*SpeedBoost;
                }else{
                    isUsedLane=false;
                }
            }else{
                if(LaneLength>0){
                    velocity=Vector2D{0,1}*VectorNorm(velocity);
                    center+=velocity*time*SpeedBoost;
                    LaneLength-=VectorNorm(velocity)*time*SpeedBoost;
                }else{
                    isUsedLane=false;
                }
            }
        }
    }
}

void Ball::draw (Interface & interface)
{
    interface.drawBall(center, radius);
}

void Ball::setCenter(Vector2D pos) {
    bool Check1 = pos.x < radius,
    Check2 = pos.x > GAME_WIDTH - radius,
    Check3 = pos.y < radius;
    Vector2D ModifiedPosition = pos;
    if(Check1)
        ModifiedPosition = { radius , pos.y };

    if(Check2)
        ModifiedPosition = { GAME_WIDTH - radius, pos.y };

    if(Check3)
        ModifiedPosition = { pos.x, radius };

    center = ModifiedPosition;
}

void Ball::setVelocity(Vector2D vel) {
    if(VectorNorm(vel) < 600){
        velocity = vel;
    } else {
        velocity = vel * VelocityControl / VectorNorm(vel);
    }
}

void Ball::Activate(bool & space) {
    if(space & isMain){
        isActive=true;
    }
}

void Ball::deActivate() {
    isActive=false;
    isUsedPortal=false;
    isUsedLane=false;
}

Vector2D Ball::collideWith(Ball &ball, float collision_time, Manager & manager) {
    if(ball.getCenter().x==center.x & ball.getCenter().y == center.y){
        return {0,0};
    }else {
        Vector2D acc = {0, 0};
        Vector2D dir;
        if (VectorDistance(ball.getCenter(), center) <= radius + ball.getRadius()) {
            //Break Captivity
            if (!isMain & !isActive){
                isActive=true;
                sound.play();
            }

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
    if(isMain){
        setCenter(InitialPosition);
        setVelocity(InitialVelocity);
    }
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

void Ball::Boost(double BoostValue) {
    BoostTimer=BoostDuration;
    SpeedBoost=BoostValue;
}

void Ball::UpdateBoost(double time) {
    if(BoostTimer>0){
        BoostTimer-=time;
    }
}

void Ball::SetLaneLength(double Length) {
    this->LaneLength=Length;
}

void Ball::SetLaneMode(bool Active) {
    isUsedLane=Active;
}

bool Ball::GetLaneMode()const{
    return isUsedLane;
}

void Ball::SetLaneDirection(bool isUp) {
    isDirectedUp=isUp;
}
