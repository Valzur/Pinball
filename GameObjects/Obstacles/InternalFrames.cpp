//
// Created by anon on 4/1/20.
//

#include "InternalFrames.h"

void InternalFrames::draw(Interface &interface) {
    interface.loadInternalFrame(bool is45,bool isLeft,float Diameter, float LineXCoordinate, float LineYCoordinate, float InclinationAngle, float setPositionX,float setPositionYRation);

}

InternalFrames::InternalFrames(bool is45, bool isLeft, float Diameter, float LineXCoordinate, float LineYCoordinate,
                               float InclinationAngle, float setPositionX, float setPositionYRation)
                               : Frames( is45, isLeft, Diameter, LineXCoordinate, LineYCoordinate, InclinationAngle, setPositionX, setPositionYRation)

                               {



                               }
