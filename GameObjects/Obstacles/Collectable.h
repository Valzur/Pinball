#pragma once

#include "Obstacle.h"
#include "../../Defs.h"
#include "../../Utility/CollisionDetection.h"

class Collectable:public Obstacle
{
private:
    double radius,Timer=FlashTimer;
    string L;
    Vector2D Center;
    bool Active=true,Used=false;
public:
    Collectable(double radius,string L,Vector2D Center);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};






