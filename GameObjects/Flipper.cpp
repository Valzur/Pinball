#include "Flipper.h"

Flipper::Flipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius):
    type(type), center(center), length(length), angle(angle), majorRadius(majorRadius), minorRadius(minorRadius) {}

Vector2D Flipper::collideWith(Ball & ball, float collision_time)
{

    Vector2D acc={0,0};
    Vector2D unitAcc;
    double speed=pow((pow(ball.getVelocity().x,2)+pow(ball.getVelocity().y,2)),0.5);

    if(ball.getCenter().y>GAME_HEIGHT*0.8)
        cout<<"1"<<endl;

    if((pow(pow(ball.getCenter().x-(center.x+length*cos(angle)),2)+pow(ball.getCenter().y-(center.y + length*sin(angle)),2),0.5)-minorRadius-ball.getRadius())<0) {
        unitAcc={center.x+length*cos(angle)-ball.getCenter().x,center.y+length*sin(angle)-ball.getCenter().y};
        unitAcc=unitAcc/(pow((pow(unitAcc.x,2)+pow(unitAcc.y,2)),0.5));
        unitAcc=unitAcc*(-1);
        acc=unitAcc*ImpulseMultiplier*speed;
    }

    if((pow(pow(ball.getCenter().x-center.x,2)+pow(ball.getCenter().y-center.y,2),0.5)-majorRadius-ball.getRadius())<0){
        unitAcc=center-ball.getCenter();
        unitAcc=unitAcc/(pow((pow(unitAcc.x,2)+pow(unitAcc.y,2)),0.5));
        unitAcc=unitAcc*(-1);
        acc=unitAcc*ImpulseMultiplier*speed;
    }

    return acc;
}

void Flipper::draw(Interface & interface)
{
    interface.drawFlipper(type, center, length, angle, majorRadius, minorRadius);
}

void Flipper::RotateFlipper(float a, float time){
    if(a>0){
        if(angle<0.7*a) {
            angle += time * FLIPPERS_ROTATE_VELOCITY;
            ImpulseMultiplier=1.5;
        }else if(angle>a/0.7){
            angle -= time * FLIPPERS_ROTATE_VELOCITY;
            ImpulseMultiplier=1.5;
        }else{
            angle=a;
            ImpulseMultiplier=1;
        }
    }else{
        if(angle<a/0.7) {
            angle += time * FLIPPERS_ROTATE_VELOCITY;
            ImpulseMultiplier=1.5;
        }else if(angle>a*0.7){
            angle -= time * FLIPPERS_ROTATE_VELOCITY;
            ImpulseMultiplier=1.5;
        }else{
            angle=a;
            ImpulseMultiplier=1;
        }
    }

}
