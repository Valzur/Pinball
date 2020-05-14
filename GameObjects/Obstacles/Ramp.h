#pragma once

#include "Obstacle.h"

class Ramp : public Obstacle{
private:
    Vector2D Center;
public:
    explicit Ramp(Vector2D Center);

    void draw(Interface& interface) override;

    Vector2D collideWith(Ball & ball, double collision_time, Manager & manager)override;

};
