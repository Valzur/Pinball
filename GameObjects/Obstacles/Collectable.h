#pragma once

#include "Obstacle.h"
class Collectable:public Obstacle
{
private:
    double radius;
    string L;
    Vector2D Center;
public:
    Collectable(double radius,string L,Vector2D Center);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};






