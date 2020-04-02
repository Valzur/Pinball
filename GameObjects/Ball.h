#pragma once

#include "Drawable.h"

// Represents the ball (the single most important object in a Pinball game!)
class Ball: public Drawn
{
private:
    const Vector2D InitialPosition,InitialVelocity;
    bool isActive,isMain;
    const float radius;  // Radius of the ball
    Vector2D center;  // The instantaneous center of the ball
    Vector2D velocity;  // The instantaneous velocity of the ball
public:
    explicit Ball(Vector2D center = INITIAL_CENTER,float radius=10, Vector2D velocity = INITIAL_VELOCITY,bool Main =true);  // Constructor

    // Accessors
    float getRadius() const;
    Vector2D getCenter() const;
    Vector2D getVelocity() const;
    bool getisMain() const;

    void setCenter(Vector2D pos);
    void setVelocity(Vector2D vel);

    void deActivate();
    void Activate(bool & space);
    void Reset();

    Vector2D BallToBallCollision(const Ball& ball);

    void move (Vector2D acceleration, float time);  // Simulates the ball's motion under uniform acceleration for a period of time

    void draw (Interface & interface) override;
};
