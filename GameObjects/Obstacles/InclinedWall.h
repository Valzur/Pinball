
#pragma once
#include "Obstacle.h"
#include "Wall.h"


class InclinedWall: public Wall
{
private:
    bool is45;
    bool isLeft;
    double Diameter;
    double LineXCoordinate;
    double LineYCoordinate;
    double InclinationAngle;
    double setPositionX;
    double setPositionYRation;

public:
    explicit InclinedWall(bool is45, bool isLeft, double Diameter, double LineXCoordinate, double LineYCoordinate, double InclinationAngle, double setPositionX, double setPositionYRation);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};

