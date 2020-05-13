#include "Lane.h"

Lane::Lane(double Length, Vector2D Center, double Width):Width(Width), Length(Length),Center(Center) {}

void Lane::SetLength(double Length){
this->Length=Length;
}

void Lane::SetCenter(Vector2D Center) {
this->Center=Center;
}

double Lane::GetLength() const {
    return Length;
}

Vector2D Lane::GetCenter() const {
    return Center;
}

void Lane::draw(Interface &interface) {
    interface.drawLane( Length, Center, Width);
}

Vector2D Lane::collideWith(Ball &ball, float collision_time, Manager &manager) {

    return {0,0};
}
