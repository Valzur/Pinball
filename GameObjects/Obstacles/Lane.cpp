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
    if(!Top)
        Top = BICCollision(ball,Vector2D {Center.x,Center.y-Length/2.0},Width);
    if(!Bottom)
        Bottom = BICCollision(ball,Vector2D {Center.x,Center.y+Length/2.0},Width);

    if(Top & Bottom){
        bool Check1 = BICCollision(ball,Vector2D {Center.x,Center.y-Length/2.0},Width),
        Check2 = BICCollision(ball,Vector2D {Center.x,Center.y+Length/2.0},Width);
        if(!Check1 & !Check2){
            Top = false;
            Bottom = false;
            ball.SetLaneMode(false);
        }
    }else if(Top){
        if (!ball.GetLaneMode()){
            ball.setCenter(Vector2D{Center.x, Center.y - Length / 2.0});
            ball.SetLaneLength(Length);
            ball.SetLaneMode(true,false);
        }
    }else if(Bottom){
        if (!ball.GetLaneMode()){
            ball.SetLaneMode(true,true);
            ball.setCenter(Vector2D {Center.x,Center.y+Length/2.0});
            ball.SetLaneLength(Length);
        }
    }

    return {0,0};
}
