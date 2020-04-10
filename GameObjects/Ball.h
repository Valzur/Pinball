#pragma once

#include "Obstacles/Obstacle.h"
#include "Manager.h"
// Represents the ball (the single most important object in a Pinball game!)
class Ball: public Drawn
{
private:
    const Vector2D InitialPosition,InitialVelocity;
    bool isActive,isMain,isUsedPortal=false;
    const float radius;  // Radius of the ball
    Vector2D center;  // The instantaneous center of the ball
    Vector2D velocity;  // The instantaneous velocity of the ball
    Vector2D Acceleration;
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

    void deActivate();
    void Activate(bool & space);
    void Reset();

    Vector2D collideWith(Ball& ball, float collision_time, Manager & manager);

    void move (float time);  // Simulates the ball's motion under uniform acceleration for a period of time

    void draw (Interface & interface) override;
};
