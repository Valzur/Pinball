#pragma once

#include <iostream>
#include "Obstacle.h"
#include <cmath>
#include "../Manager.h"
#include "../../Defs.h"

using namespace std;

class Bumper : public Obstacle{
private:
    Vector2D position;
    float radius;
public:

    Bumper(Vector2D pos, float rad);

    Vector2D GetPosition();
    float GetRadius();

    Vector2D collideWith(Ball& ball, float collision_time, Manager & manager) override;
    void draw(Interface & interface) override;
};