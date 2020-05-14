#include "Gate.h"

void Gate::draw(Interface &interface) {
    interface.drawGate(length,width,setPositionX,setPositionY);
}

Gate::Gate(double setPositionX, double setPositionY, double length, double width) {
    this->setPositionX=setPositionX;
    this->setPositionY=setPositionY;
    this->length=length;
    this->width=width;
}

Vector2D Gate::collideWith(Ball &ball, double collision_time, Manager &manager) {
    return{0,0};
}
