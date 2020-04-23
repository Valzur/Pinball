#pragma once
#include "../Defs.h"
#include "../GameObjects/Ball.h"


    Vector2D CircleCollision(const Ball& ball,Vector2D position,double radius, double collision_time);
    bool BICCollision(const Ball& ball,Vector2D position,double radius);