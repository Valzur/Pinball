#pragma once

#include "Obstacle.h"

class Kicker : public Obstacle
{
private:
float x1,x2,x3,y1,y2,y3;
public:
    Kicker(float x1, float x2, float x3, float y1, float y2, float y3);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, float collision_time, Manager & manager) override;
};



