#include "Ramp.h"

void Ramp::draw(Interface &interface) {
    interface.drawRamp(is45, isLeft, Diameter, Size, InclinationAngle, x,setPositionYRation);

}

Ramp::Ramp(bool is45, bool isLeft, double Diameter,Vector2D Size,
        double InclinationAngle, double x, double setPositionYRation){
    this->is45=is45;
    this->isLeft=isLeft;
    this->Diameter=Diameter;
    this->Size=Size;
    this->InclinationAngle=InclinationAngle;
    this->x=x;
    this->setPositionYRation=setPositionYRation;
}

Vector2D Ramp::collideWith(Ball &ball, double collision_time, Manager &manager) {

    return{0,0};
}
