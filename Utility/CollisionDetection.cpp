#include "CollisionDetection.h"

Vector2D CircleCollision(const Ball& ball,Vector2D position, double radius, double collision_time) {
    Vector2D Acceleration = {0, 0},Velocity;

        double ScalarVelocity = VectorNorm(ball.getVelocity());
        if (VectorDistance(ball.getCenter(), position) < radius + ball.getRadius()) {
            Velocity = ball.getVelocity() - (ball.getCenter() - position) *
                    (DotProduct((ball.getVelocity()), (ball.getCenter() - position))) /
                    pow(VectorNorm(position - ball.getCenter()), 2);
            Velocity = Velocity / VectorNorm(Velocity);
            Acceleration = Vector2D {-Velocity.y,Velocity.x} * ScalarVelocity / collision_time;
        }
    return Acceleration;
}

bool BICCollision(Ball &ball, Vector2D position, double radius) {
    bool detected = false;
    if (VectorDistance(ball.getCenter(), position) <= radius - ball.getRadius())
        detected = true;

    return detected;
}

Vector2D Lcollision(const Ball& ball, Vector2D Position, double L, double W, double collision_time) {
    Vector2D Acceleration = { 0,0 }, v;
    bool isbetween = InRange(ball.getCenter().x, Position.x + L/2, Position.x-L/2);
    if (isbetween && abs(ball.getCenter().y - Position.y) <= ball.getRadius()+W/2) {
        Acceleration = { ball.getVelocity().x * -2,ball.getVelocity().y * -2 };
        Acceleration = Acceleration / collision_time;
    }
    return Acceleration;

}
bool InRange(double value, double max, double min)
{
    return value >= min && value <= max;
}

Vector2D LineCollision(Ball &ball, double Length, double Angle, Vector2D Center) {
    Vector2D Velocity={0,0},DynamicCenter=Center;
    int Radius=ball.getRadius(),NoOfIterations = Length/Radius;
    bool Signal = false;
    //Checking
    for (int i = 0; i < NoOfIterations; i++) {
        DynamicCenter+= Vector2D {cos(Angle/180*PI),sin(Angle/180*PI)}*Radius;
        if(BOCCollision(ball,DynamicCenter,Radius)){
            Signal = true;
            std::cout << "Signal" << std::endl;
            break;
        }
    }
    if(Signal){
        double ScalarVelocity = VectorNorm(ball.getVelocity());
    }

    return Velocity;
}

bool BOCCollision(Ball &ball, Vector2D position, double radius) {
    bool detected = false;
    if (VectorDistance(ball.getCenter(), position) <= radius + ball.getRadius() )
        detected = true;

    return detected;
}
