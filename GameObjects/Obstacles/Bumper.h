#pragma once

#include <iostream>
#include "Obstacle.h"
#include <cmath>
#include "../Manager.h"
#include "../../Defs.h"
#include "../../Utility/CollisionDetection.h"

using namespace std;

class Bumper : public Obstacle{
private:
    Vector2D position;
    double radius;
    int bscore;
    BumperType type;
public:
    Bumper(Vector2D pos, double rad, BumperType type);

    //Getters
    Vector2D GetPosition();
    double GetRadius() ;
    BumperType GetType();

    //Setters
    void setScorepoints(int x);

    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
    void draw(Interface & interface) override;
};