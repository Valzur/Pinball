#pragma once

#include "InclinedWall.h"


class Ramp : public InclinedWall
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
    explicit Ramp(bool is45, bool isLeft, double Diameter, double LineXCoordinate, double LineYCoordinate, double InclinationAngle, double setPositionX, double setPositionYRation);
//    void draw(Interface & interface);
//
//    void draw(Interface& interface) override;
//
//    Vector2D collideWith(Ball & ball, double collision_time, Manager & manager)override;

};
