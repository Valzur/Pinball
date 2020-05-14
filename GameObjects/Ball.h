#pragma once

#include "Obstacles/Obstacle.h"
#include "Manager.h"
#include <iostream>
#include "../Defs.h"

// Represents the ball (the single most important object in a Pinball game!)
class Ball: public Drawn
{
private:
    const Vector2D InitialPosition,InitialVelocity;
    bool isActive,isMain,isUsedPortal=false,isUsedLane=false;
    const double radius, BoostDuration=0.5;
    Vector2D center;  // The instantaneous center of the ball
    Vector2D velocity;  // The instantaneous velocity of the ball
    Vector2D Acceleration;
    double BoostTimer=0.0, SpeedBoost=1.0;

    //Lane Attributes
    Vector2D LaneCenter;
    double LaneLength,LaneVelocity,LaneProgress;
public:
    explicit Ball(Vector2D center = INITIAL_CENTER,float radius=10, Vector2D velocity = INITIAL_VELOCITY,bool Main =true);  // Constructor

    // Accessors
    float getRadius() const;
    Vector2D getCenter() const;
    Vector2D getVelocity() const;
    Vector2D getAcceleration() const;
    bool getisMain() const;
    bool getIsUsedPortal() const;

    void setUsedPortal(bool Used);
    void setCenter(Vector2D pos);
    void setVelocity(Vector2D vel);
    void setAcceleration(Vector2D Acceleration);
    void SetLaneAttributes(double Length, Vector2D Center);
    void SetLaneMode(bool Active);

    void deActivate();
    void Activate(bool & space);
    void Reset();
    void Boost(double BoostValue);
    void UpdateBoost(double time);

    Vector2D collideWith(Ball& ball, float collision_time, Manager & manager);

    void move (double time, Manager& manager,bool &lost);  // Simulates the ball's motion under uniform acceleration for a period of time

    void draw (Interface & interface) override;
};
