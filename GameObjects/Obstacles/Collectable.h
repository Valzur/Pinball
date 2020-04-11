//
// Created by anon on 4/11/20.
//

#pragma once

#include "Obstacle.h"
class Collectable:public Obstacle
{
private:
    float radius;
    string L;
public:
    Collectable(float radius,string L);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, float collision_time, Manager & manager) override;
};






