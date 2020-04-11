//
// Created by anon on 4/1/20.
//

#include "InternalFrames.h"

void InternalFrames::draw(Interface &interface) {
    interface.loadInternalFrame( is45,isLeft, Diameter, LineXCoordinate, LineYCoordinate, InclinationAngle, setPositionX, setPositionYRation);

}

InternalFrames::InternalFrames(bool is45, bool isLeft, float Diameter, float LineXCoordinate, float LineYCoordinate,
                               float InclinationAngle, float setPositionX, float setPositionYRation)


                               {
this->is45=is45;
this->isLeft=isLeft;
this->Diameter=Diameter;
this->LineXCoordinate=LineXCoordinate;
this->LineYCoordinate=LineYCoordinate;
this->InclinationAngle=InclinationAngle;
this->setPositionX=setPositionX;
this->setPositionYRation=setPositionYRation;


                               }

Vector2D InternalFrames::collideWith(Ball &ball, float collision_time, Manager &manager) {
    return {0,0};
}
