#pragma once
#include "Obstacle.h"




class Wall : public Obstacle
        {
private:
    bool isVertical;
    float Position;
    bool collidedLastFrame;
public:
    explicit Wall(bool isVertical, float Position);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};



