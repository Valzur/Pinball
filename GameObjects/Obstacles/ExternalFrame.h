#pragma once
#include "Obstacle.h"




class ExternalFrame:public Obstacle{
private:
    bool isVertical;
    float Position;
public:
    explicit ExternalFrame(bool isVertical, float Position);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};



