//
// Created by anon on 4/10/20.
//

#include "ExternalFrame.h"

ExternalFrame::ExternalFrame(bool isVertical, float Position) {
this->isVertical=isVertical;
this->Position=Position;
}

void ExternalFrame::draw(Interface &interface) {
    interface.loadExternalFrame( isVertical,  Position);

}

Vector2D ExternalFrame::collideWith(Ball &ball, double collision_time, Manager &manager) {
    return {0,0};
}
