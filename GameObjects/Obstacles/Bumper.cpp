#include "Bumper.h"

float Bumper::GetRadius() {
    return radius;
}

Vector2D Bumper::collideWith(Ball &ball, float collision_time, Manager & manager) {
    float actualRadius, Modificationfactor, Acc, velocity;
    Vector2D ModifiedRadiusPos;
    velocity = VectorNorm(ball.getVelocity());
    Vector2D acc = ball.getCenter()-position;
    actualRadius = VectorNorm(acc);
    if (actualRadius <= (ball.getRadius() + radius)) {

        //Adjusting position if ball goes inside the bumper
        Modificationfactor = ball.getRadius() + radius - actualRadius;
        ModifiedRadiusPos = acc*Modificationfactor;
        ModifiedRadiusPos += ball.getCenter();

        //Calculating response
        acc = {-ball.getVelocity().y + position.y, ball.getVelocity().x - position.y};
        Acc=VectorNorm(acc);
        acc = acc /Acc;
        acc= acc*velocity/collision_time;

        //Add score
        manager.addScore(bscore);
        //Returning values
        ball.setCenter(ModifiedRadiusPos);
        return acc;
    } else {
        return {0, 0};
    }
    //Copy everything for the thrust bumper.
    /*
    float actualRadius, Modificationfactor, Acc, velocity;
    Vector2D ModifiedRadiusPos;
    velocity = pow((pow(ball.getVelocity().x, 2) + pow(ball.getVelocity().y, 2)), 0.5);
    Vector2D acc = {ball.getCenter().x - position.x, ball.getCenter().y - position.y};
    actualRadius = pow((pow(acc.x, 2) + pow(acc.y, 2)), 0.5);
    if (actualRadius <= (ball.getRadius() + radius)) {

        //Adjusting position if ball goes inside the bumper
        Acc = pow((pow(acc.x, 2) + pow(acc.y, 2)), 0.5);
        Modificationfactor = ball.getRadius() + radius - actualRadius;
        ModifiedRadiusPos = {Modificationfactor * acc.x / Acc, Modificationfactor * acc.y / Acc};
        ModifiedRadiusPos += ball.getCenter();

        //Calculating response
        acc = {-ball.getVelocity().y + position.y, ball.getVelocity().x - position.y};
        acc = acc * Acc;

        //Add score
        manager.addScore(50);

        //Returning values
        ball.setCenter(ModifiedRadiusPos);
        return acc;
    } else {
        return {0, 0};
    }
    */
}

Bumper::Bumper(Vector2D pos, float rad, BumperType type): type(type) {
    position=pos;
    radius=rad;
}

Vector2D Bumper::GetPosition(){
    return position;
}

void Bumper::draw(Interface &interface) {
    //interface.drawBumper(position,radius,type);
}

void Bumper::setScorepoints(int x) {
    bscore = x;
}

BumperType Bumper::GetType() {
    return type;
}
