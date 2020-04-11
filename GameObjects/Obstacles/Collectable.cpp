#include "Collectable.h"

Collectable::Collectable(float radius, string L,Vector2D Center): Center(Center) {
    this->radius=radius;
    this->L=L;

}

void Collectable::draw(Interface &interface)
{
    interface.drawCollectable(radius,L,Center);
}

Vector2D Collectable::collideWith(Ball &ball, float collision_time, Manager &manager)
{
    return {0,0};
}
