//
// Created by anon on 4/10/20.
//
#pragma once

#include "Obstacle.h"
//This is a kicker not a speedboaster
class SpeedBoaster :public Obstacle
{
private:
float x1,x2,x3,y1,y2,y3;

public:
    SpeedBoaster(float x1,float x2,float x3,float y1,float y2,float y3);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, float collision_time, Manager & manager) override;
};



