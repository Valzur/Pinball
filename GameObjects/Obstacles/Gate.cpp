#include "Gate.h"

void Gate::draw(Interface &interface) {
    interface.drawGate(length,width,Center, AllowUp);
}

Gate::Gate(Vector2D Center, double length, double width,bool AllowUp) {
    this->Center.x=Center.x;
    this->Center.y=Center.y;
    this->length=length;
    this->width=width;
    this->AllowUp=AllowUp;
}

Vector2D Gate::collideWith(Ball &ball, double collision_time, Manager &manager) {
    if( (ball.getCenter().x > Center.x - length/2.0) & ( ball.getCenter().x < Center.x + length/2.0) ){
        //Control parameter for perfectionists :'D
        int Direction;
        if(AllowUp){
            Direction=1;
        }else{
            Direction=-1;
        }

        if(VectorDistance(ball.getCenter(),Vector2D{Center.x,Center.y+Direction*width/2.0})<= ball.getRadius()){
            if(AllowUp){
                if(ball.getVelocity().y<0){
                    ball.setVelocity(Vector2D {ball.getVelocity().x,-ball.getVelocity().y});
                }
            }else{
                if(ball.getVelocity().y>0){
                    ball.setVelocity(Vector2D {ball.getVelocity().x,-ball.getVelocity().y});
                }
            }
        }
    }

    return {0,0};
}
