#pragma once

#include "Obstacle.h"

class Bullseye : public Obstacle{
private:
    Vector2D Center;
    double Length;
    const double width=GlobalWidth;
    bool isVertical=false,collidedLastFrame=false;
public:
    Bullseye(Vector2D Center, double Length, bool isVertical);

    void draw(Interface& interface)override;
    Vector2D collideWith(Ball & ball, double collision_time, Manager & manager)override;
};
