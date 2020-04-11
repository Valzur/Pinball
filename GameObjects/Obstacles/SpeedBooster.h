#pragma once

#include "Obstacle.h"
class SpeedBooster :public Obstacle{
private:
    float radius;
    Vector2D Center;
public:
    SpeedBooster(float radius, Vector2D Center);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, float collision_time, Manager & manager) override;
};




