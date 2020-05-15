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

Vector2D Lane::collideWith(Ball &ball, double collision_time, Manager &manager) {
        Top = BICCollision(ball,Vector2D {Center.x,Center.y-Length/2.0},Width);
        Bottom = BICCollision(ball,Vector2D {Center.x,Center.y+Length/2.0},Width);

    if(Top & Bottom){
        bool Check1 = BICCollision(ball,Vector2D {Center.x,Center.y-Length/2.0},Width),
        Check2 = BICCollision(ball,Vector2D {Center.x,Center.y+Length/2.0},Width);
        if(!Check1 & !Check2){
            ball.SetLaneMode(false);
        }
    } else if (Bottom & !ball.GetLaneMode()){
        ball.setCenter(Vector2D {Center.x,Center.y+Length/2.0});
        ball.SetLaneMode(true);
        ball.SetLaneDirection(true);
        ball.SetLaneLength(Length+Width);
    } else if (Top & !ball.GetLaneMode()){
        ball.setCenter(Vector2D {Center.x,Center.y-Length/2.0});
        ball.SetLaneMode(true);
        ball.SetLaneDirection(false);
        ball.SetLaneLength(Length+Width);
    }

    return {0,0};
}
