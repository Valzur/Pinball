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

Vector2D RectangleCollision(Ball &ball, double Length, double Width, double Angle, Vector2D Center) {
    Vector2D Velocity ={0,0}, DynamicCenter=Center, TDirection = {cos(Angle/180*PI),sin(Angle/180*PI)},
    NDirection = {TDirection.y,-TDirection.x};
    int Radius=ball.getRadius(),NoOfIterations = Length/Radius;
    bool Signal = false;
    //Checking
    for (int i = 0; i < NoOfIterations; i++) {
        Vector2D NormalCenter1,NormalCenter2;
        double Distance1,Distance2;
        //Increment in the x axis
        DynamicCenter += TDirection * Radius;
        //Increment in the y axis
        NormalCenter1 = DynamicCenter + NDirection * Width/2.0;
        NormalCenter2 = DynamicCenter - NDirection * Width/2.0;
        //Check Distances
        Distance1 = VectorDistance(NormalCenter1,ball.getCenter());
        Distance2 = VectorDistance(NormalCenter2,ball.getCenter());

        if( Distance1 < ball.getRadius() & Distance2 < ball.getRadius() ){
            //It is close to both points
            if( Distance1 < Distance2 ){
                //Closer to point 1
                Velocity = ball.getVelocity() - NDirection*DotProduct(ball.getVelocity(),NDirection)/DotProduct(NDirection,NDirection) * 2;
                break;
            }else{
                //Closer to point 2
                Velocity = ball.getVelocity() + NDirection*DotProduct(ball.getVelocity(),NDirection*-1)/DotProduct(NDirection*-1,NDirection*-1) * 2;
                break;
            }
        } else if ( Distance1 < ball.getRadius() ){
            //Closer to point 1
            Velocity = ball.getVelocity() - NDirection*DotProduct(ball.getVelocity(),NDirection)/DotProduct(NDirection,NDirection) * 2;
            break;
        } else if ( Distance2 < ball.getRadius() ){
            //Closer to point 2
            Velocity = ball.getVelocity() + NDirection*DotProduct(ball.getVelocity(),NDirection*-1)/DotProduct(NDirection*-1,NDirection*-1) * 2;
            break;
        }
    }
    if(Velocity!=Vector2D{0,0}){
        Velocity = Velocity * VectorNorm(ball.getVelocity()) / VectorNorm(Velocity);
    }
    return Velocity;
}

bool BOCCollision(Ball &ball, Vector2D position, double radius) {
    bool detected = false;
    if (VectorDistance(ball.getCenter(), position) <= radius + ball.getRadius() )
        detected = true;

    return detected;
}
