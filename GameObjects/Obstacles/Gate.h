#pragma once

#include "Obstacle.h"


class Gate : public Obstacle
{
private:
    Vector2D Center;
    double length;
    double width;
    bool AllowUp;
public:
    Gate(Vector2D Center,double length,double width, bool AllowUp = true);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};
