#pragma once

#include "Ball.h"
#include "Manager.h"

class Manager;

class Ball;

// An interface class that should be implemented by any class that can apply force on the ball upon collision
class Collidable
{
public:
    virtual Vector2D collideWith(Ball & ball, double collision_time, Manager & manager) = 0;  // Simulates a collision with the ball (if any) and returns the contribution of the collision on the ball's acceleration
};
