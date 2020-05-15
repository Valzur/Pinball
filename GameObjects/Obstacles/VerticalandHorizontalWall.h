#pragma once
#include "Obstacle.h"
#include "Wall.h"



class VerticalandHorizontalWall: public Wall
        {
private:
    bool isVertical;
    float Position;
    bool collidedLastFrame;
public:
    explicit VerticalandHorizontalWall(bool isVertical, float Position);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager) override;
};



