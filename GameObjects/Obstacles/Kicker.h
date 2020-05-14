#pragma once

#include "Obstacle.h"

class Kicker : public Obstacle
{
private:
    double x1,x2,x3,y1,y2,y3;
public:
    Kicker(double x1, double x2, double x3, double y1, double y2, double y3);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};



