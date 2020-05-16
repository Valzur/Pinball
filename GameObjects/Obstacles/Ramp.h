
#pragma once
#include "Obstacle.h"



class Ramp : public Obstacle
{
private:
    bool is45;
    bool isLeft;
    double Diameter;
    Vector2D Size;
    double InclinationAngle;
    double x;
    double setPositionYRation;

public:
    explicit Ramp(bool is45, bool isLeft, double Diameter, Vector2D Size, double InclinationAngle, double x, double setPositionYRation);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};

