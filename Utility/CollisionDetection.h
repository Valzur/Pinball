#pragma once
#include "../Defs.h"
#include "../GameObjects/Ball.h"


    Vector2D CircleCollision(const Ball& ball,Vector2D position,double radius, double collision_time);
    bool BICCollision(Ball& ball,Vector2D position,double radius);
    Vector2D Lcollision(const Ball& ball, Vector2D Position, double L, double W, double collision_time);
    bool InRange(double value, double max, double min);