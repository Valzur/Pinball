#pragma once

#include "../../Utility/CollisionDetection.h"
#include "Obstacle.h"

class Portal : public Obstacle{
private:
    Vector2D Pos1;
    Vector2D Pos2;
    double radius=5;
public:
    Portal(Vector2D Pos1,Vector2D Pos2,double radius=35);
    void draw(Interface & interface)override;
    Vector2D collideWith(Ball & ball, double collision_time, Manager & manager)override;
};

