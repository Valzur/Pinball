

#include "Bumper.h"

float Bumper::GetRadius() {
    return radius;
}

Vector2D Bumper::collidewith(Ball &ball, float collision_time) {
    double R;
    Vector2D acc={ball.getCenter().x-position.x,ball.getCenter().y-position.y};
    R=pow((pow(acc.x,2)+pow(acc.y,2)),0.5);
    if(R<=(ball.getRadius()+radius)){
        acc=acc/R*ball.getVelocity()/collision_time;
        return acc;
    }else{
        return {0,0};
    }
}

Bumper::Bumper(Vector2D pos, int rad) {
    position=pos;
    radius=rad;
}

Vector2D Bumper::GetPosition() {
    return position;
}


