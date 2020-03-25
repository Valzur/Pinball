#pragma once

#include <iostream>
#include "Obstacle.h"
#include <cmath>
#include "../Manager.h"
#include "../../Defs.h"

using namespace std;

enum BumperType{
    Pop,
    Thrust,
    Vibranium
};

class Bumper {
private:
    Vector2D position;
    float radius;
    BumperType type;
public:

    Bumper(Vector2D pos, int rad,BumperType Type);

    Vector2D GetPosition();
    float GetRadius();

    Vector2D collidewith(Ball& ball, float collision_time, Manager & manager);
};