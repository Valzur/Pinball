//
// Created by anon on 4/10/20.
//
#pragma once
#include "Obstacle.h"




class ExternalFrame:public Obstacle
        {
private:
            bool isVertical;
            float Position;

public:
            explicit ExternalFrame(bool isVertical, float Position);
    void draw(Interface & interface) override;
};



