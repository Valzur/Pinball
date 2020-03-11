

#include "Bumper.h"

float Bumper::GetRadius() {
    return radius;
}

Vector2D Bumper::collidewith(Ball &ball, float collision_time, Manager & manager) {
<<<<<<< HEAD
    float actualRadius,Modificationfactor,Acc;
    Vector2D ModifiedRadiusPos;
=======
    float actualRadius,Modificationfactor,Acc,velocity;
    Vector2D ModifiedRadiusPos;
    velocity=pow((pow(ball.getVelocity().x,2)+pow(ball.getVelocity().y,2)),0.5);
>>>>>>> master
    Vector2D acc={ball.getCenter().x-position.x,ball.getCenter().y-position.y};
    actualRadius=pow((pow(acc.x,2)+pow(acc.y,2)),0.5);
    if(actualRadius<=(ball.getRadius()+radius)){
        //Adjusting position if ball goes inside the bumper
        Acc=pow((pow(acc.x,2)+pow(acc.y,2)),0.5);
        Modificationfactor = ball.getRadius()+radius-actualRadius;
        ModifiedRadiusPos={Modificationfactor*acc.x/Acc,Modificationfactor*acc.y/Acc};
        ModifiedRadiusPos+=ball.getCenter();

        //Calculating response
        acc={-ball.getVelocity().y+position.y,ball.getVelocity().x-position.y};
<<<<<<< HEAD
        acc={static_cast<float>(1.5*Acc*acc.x), static_cast<float>(1.5*Acc*acc.y)};
=======
        acc={static_cast<float>(1.0*Acc*acc.x), static_cast<float>(1.0*Acc*acc.y)};
        //acc=acc/(pow((pow(acc.x,2)+pow(acc.y,2)),0.5));
        //acc=acc*velocity*5.0;
>>>>>>> master

        //Add score
        manager.addScore(50);

        //Debug
        //cout << "Actual radius is: " << radius + ball.getRadius() << endl;
        //cout << "Modified radius is: " << pow((pow(ModifiedRadiusPos.x-position.x,2)+pow(ModifiedRadiusPos.y-position.y,2)),0.5)<< endl;

        //Returning values
        ball.setCenter(ModifiedRadiusPos);
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


