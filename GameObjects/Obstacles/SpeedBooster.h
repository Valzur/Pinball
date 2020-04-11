//
// Created by anon on 4/11/20.
//
#pragma once

#include "Obstacle.h"
class SpeedBooster :Obstacle

{
private:
    float radius;
private:
    SpeedBooster(float radius);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, float collision_time, Manager & manager) override;
};




