#pragma once

#include "Obstacle.h"
#include "../../Utility/CollisionDetection.h"

class SpeedBooster :public Obstacle{
private:
    double radius,HitTimer=FlashTimer;
    Vector2D Center;
    bool Hit=false;
public:
    SpeedBooster(double radius, Vector2D Center);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};




