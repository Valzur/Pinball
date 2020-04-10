
#pragma once
#include "Obstacle.h"



class InternalFrames: public Obstacle
{
private:
    bool is45;
    bool isLeft;
    float Diameter;
    float LineXCoordinate;
    float LineYCoordinate;
    float InclinationAngle;
    float setPositionX;
    float setPositionYRation;

public:
    explicit InternalFrames(bool is45,bool isLeft,float Diameter, float LineXCoordinate, float LineYCoordinate, float InclinationAngle, float setPositionX,float setPositionYRation);
    void draw(Interface & interface) override;

};

//PINBALL_INTERNALFRAMES_H
