#include "Portal.h"

void Portal::draw(Interface &interface) {
    interface.drawPortals(Pos1,Pos2,radius);
}

Portal::Portal(Vector2D Pos1, Vector2D Pos2, double radius): Pos1(Pos1),Pos2(Pos2),radius(radius) {}

Vector2D Portal::collideWith(Ball &ball, float collision_time, Manager &manager) {
    bool Check1,Check2;
    Check1=BICCollision(ball,Pos1,radius);
    Check2=BICCollision(ball,Pos2,radius);
    if(Check1){
        if(!ball.getIsUsedPortal()){
            ball.setCenter(Pos2);
            ball.setUsedPortal(true);
        }
    }else if(Check2){
        if(!ball.getIsUsedPortal()){
            ball.setCenter(Pos1);
            ball.setUsedPortal(true);
        }
    }else{
        ball.setUsedPortal(false);
    }
    return {0,0};
}

