#include "Ramp.h"

Ramp::Ramp(bool is45, bool isLeft, double Diameter, double LineXCoordinate, double LineYCoordinate, double InclinationAngle, double setPositionX, double setPositionYRation):
        InclinedWall( is45,  isLeft, Diameter,  LineXCoordinate, LineYCoordinate,  InclinationAngle,  setPositionX,  setPositionYRation)
{}
//void draw(Interface & interface): Center(Center) {}
//
//void Ramp::draw(Interface &interface) {
//    interface.drawRamp(Center);
//}
//
//Vector2D Ramp::collideWith(Ball &ball, double collision_time, Manager &manager) {
//
//
//    return {0,0};
//}
