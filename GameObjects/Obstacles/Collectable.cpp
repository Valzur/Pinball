//
// Created by anon on 4/11/20.
//

#include "Collectable.h"

Collectable::Collectable(float radius, string L) {
    this->radius=radius;
    this->L=L;

}

void Collectable::draw(Interface &interface)
{
    interface.drawCollectable(radius,L);

}

Vector2D Collectable::collideWith(Ball &ball, float collision_time, Manager &manager)
{
    return {0,0};
}
