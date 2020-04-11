#pragma once

#include "Obstacle.h"
class Collectable:public Obstacle
{
private:
    float radius;
    string L;
    Vector2D Center;
public:
    Collectable(float radius,string L,Vector2D Center);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, float collision_time, Manager & manager) override;
};






