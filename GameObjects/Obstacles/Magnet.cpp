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
    Vector2D Acceleration={0,0};
    if(VectorDistance(Position,ball.getCenter())<ball.getRadius()+Magnetradius){
        if(VectorDistance(Position,ball.getCenter())<ball.getRadius()+radius){
            //Collision.

        }else{
            //Magnet effect.

        }
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
