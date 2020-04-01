#pragma once

#include "Obstacle.h"

// Represents a thin vertically infinite wall, on which the ball can bounce
class Wall: public Obstacle
{
private:
    float position;  // The horizontal position of the wall
    bool collidedLastFrame;  // Whether or not the last frame was a collision (to prevent flapping)
    bool isVertical;

public:
    explicit Wall(float position,bool vertical);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball & ball, float collision_time, Manager & manager) override;
};



