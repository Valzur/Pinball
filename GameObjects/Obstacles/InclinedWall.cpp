#include "InclinedWall.h"

void InclinedWall::draw(Interface &interface) {
    interface.loadInclinedWall(is45, isLeft, Diameter, LineXCoordinate, LineYCoordinate, InclinationAngle, setPositionX,
                               setPositionYRation);

}

InclinedWall::InclinedWall(bool is45, bool isLeft, double Diameter, double LineXCoordinate, double LineYCoordinate,
                           double InclinationAngle, double setPositionX, double setPositionYRation) : Wall(LineYCoordinate, !is45)
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

Vector2D InclinedWall::collideWith(Ball &ball, double collision_time, Manager &manager) {

}
