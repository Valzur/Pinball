#include "InternalFrames.h"

void InternalFrames::draw(Interface &interface) {
    interface.loadInternalFrame( is45,isLeft, Diameter, LineXCoordinate, LineYCoordinate, InclinationAngle, setPositionX, setPositionYRation);

}

InternalFrames::InternalFrames(bool is45, bool isLeft, double Diameter, double LineXCoordinate, double LineYCoordinate,
                               double InclinationAngle, double setPositionX, double setPositionYRation){
this->is45=is45;
this->isLeft=isLeft;
this->Diameter=Diameter;
this->LineXCoordinate=LineXCoordinate;
this->LineYCoordinate=LineYCoordinate;
this->InclinationAngle=InclinationAngle;
this->setPositionX=setPositionX;
this->setPositionYRation=setPositionYRation;
}

Vector2D InternalFrames::collideWith(Ball &ball, double collision_time, Manager &manager) {
    return {0,0};
}
