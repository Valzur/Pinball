#pragma once
#include "Obstacle.h"

class Wall : public Obstacle
        {
private:
    bool isVertical;
    Vector2D Center;
    bool collidedLastFrame=false;
public:
    explicit Wall(bool isVertical, Vector2D Center);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};



