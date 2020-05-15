//
// Created by anon on 4/10/20.
//

#include "VerticalandHorizontalWall.h"

VerticalandHorizontalWall::VerticalandHorizontalWall(bool isVertical, float Position) : Wall(Position, isVertical)
{

}

void VerticalandHorizontalWall::draw(Interface &interface)
{
    interface.loadVerticalandHorizontalWall(isVertical, Position);

}

Vector2D VerticalandHorizontalWall::collideWith(Ball &ball, double collision_time, Manager &manager) {

}
