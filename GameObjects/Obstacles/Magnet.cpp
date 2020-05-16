#include "Magnet.h"

Magnet::Magnet(Vector2D Position, double Magnetradius, double radius):Position(Position),Magnetradius(Magnetradius),radius(radius) {
    if(!texture.loadFromFile("../Assets/Sprites/Magnet.png")){
        cout << "Error, unable to load Magnet texture!" << endl;
    }else{
        sprite.setTexture(texture);
    }
}

void Magnet::draw(Interface &interface) {
    interface.drawMagnet(Position,Magnetradius,radius,&sprite);
}

Vector2D Magnet::collideWith(Ball &ball, double collision_time, Manager &manager) {
    Vector2D Acceleration = { 0,0 }, velocity,farD,NewVelocity;
    double ScalarVelocity = VectorNorm(ball.getVelocity()), distance = 250;
    velocity = ball.getVelocity() ;
    farD = VectorDirection( ball.getCenter(),Position);
    int z = 1;
    if (VectorDistance(ball.getCenter(), Position) <= 100 + ball.getRadius() + Magnetradius) {


        NewVelocity = { -velocity.x + farD.x,-velocity.y + farD.y };//direction for acceleration

        Acceleration = NewVelocity / VectorNorm(NewVelocity) * ScalarVelocity;   //made time=1s, we don't care very much for time in this case as it happens continously
    }



    return Acceleration;
}

double Magnet::getMagnetRadius() const {
    return Magnetradius;
}

double Magnet::getRadius() const {
    return radius;
}

Vector2D Magnet::getCenter() const {
    return Position;
}

void Magnet::setMagnetRadius(double magnetRadius) {
    Magnetradius=magnetRadius;
}

void Magnet::setRadius(double radius) {
    this->radius=radius;
}
