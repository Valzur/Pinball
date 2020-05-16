
#pragma once
#include "Obstacle.h"
#include "../../Utility/CollisionDetection.h"

class Ramp : public Obstacle
{
private:
    bool is45;
    bool isLeft;
    double Diameter;
    //Ezat
    Vector2D Size, Center;
    double Angle;

    double x;
    double setPositionYRation = 0;

public:
    Ramp(Vector2D Size, Vector2D Center, double Angle);
    Ramp(bool is45, bool isLeft, double Diameter, Vector2D Size, double Angle, double x, double setPositionYRation);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};

