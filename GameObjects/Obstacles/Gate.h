#pragma once

#include "Obstacle.h"


class Gate : public Obstacle
{
private:
    double setPositionX;
    double setPositionY;
    double length;
    double width;
public:
    Gate(double setPositionX,double setPositionY,double length,double width);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};
