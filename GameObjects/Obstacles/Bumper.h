#pragma once

#include <iostream>
#include "Obstacle.h"
#include <cmath>

using namespace std;

class Bumper {
private:
    Vector2D position;
    float radius;
public:
    Bumper(Vector2D pos, int rad);
    Vector2D GetPosition();
    float GetRadius();
    Vector2D collidewith(Ball& ball, float collision_time);
};