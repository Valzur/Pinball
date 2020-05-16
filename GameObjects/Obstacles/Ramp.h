
#pragma once
#include "Obstacle.h"
#include "../../Utility/CollisionDetection.h"

class Ramp : public Obstacle
{
private:

    //Ezat
    Vector2D Size, Center;
    double Angle;
    int FramesTillNextCollision = 0;
public:
    Ramp(Vector2D Size, Vector2D Center, double Angle);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};

