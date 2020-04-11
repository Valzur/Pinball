#include "Kicker.h"
//Note that you just need one file to read both boasters
void Kicker::draw(Interface &interface) {
    interface.drawRightKicker(x1,y1,x2,y2,x3,y3);
    interface.drawLeftKicker(x1+30,y1,x2+30,y2,x3+30,y3);
}

Kicker::Kicker(float x1, float x2, float x3, float y1, float y2, float y3) {
    this->x1=x1;
    this->x3=x3;
    this->x2=x2;
    this->y1=y1;
    this->y2=y2;
    this->y3=y3;
}

Vector2D Kicker::collideWith(Ball &ball, float collision_time, Manager &manager) {
    return {0,0};
}
