//
// Created by anon on 4/11/20.
//
#pragma once

#include "Obstacle.h"


class Gate : public Obstacle
{
private:
    float setPositionX;
    float setPositionY;
    float length;
    float width;
public:
    Gate(float setPositionX,float setPositionY,float length,float width);
    void draw(Interface & interface) override;

};



