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
    int bscore;
    BumperType type;
public:
    Bumper(Vector2D pos, float rad, BumperType type);

    //Getters
    Vector2D GetPosition();
    float GetRadius() ;
    BumperType GetType();

    //Setters
    void setScorepoints(int x);

    Vector2D collideWith(Ball& ball, float collision_time, Manager & manager) override;
    void draw(Interface & interface) override;
};