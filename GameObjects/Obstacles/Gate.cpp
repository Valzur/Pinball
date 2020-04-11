//
// Created by anon on 4/11/20.
//

#include "Gate.h"

void Gate::draw(Interface &interface) {
    interface.drawGate(length,width,setPositionX,setPositionY);

}

Gate::Gate(float setPositionX, float setPositionY, float length, float width) {
    this->setPositionX=setPositionX;
    this->setPositionY=setPositionY;
    this->length=length;
    this->width=width;
}
