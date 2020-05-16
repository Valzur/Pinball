#include "Magnet.h"

Magnet::Magnet(Vector2D Position, double Magnetradius, double radius):Position(Position),Magnetradius(Magnetradius),radius(radius) {
    if(!texture.loadFromFile("../Assets/Sprites/Magnet.png")){
        cout << "Error, unable to load Magnet texture!" << endl;
    }else{
        sprite.setTexture(texture);
    }
    if(buffer.loadFromFile("../Assets/SFX/Magnet.wav")){
        sound.setBuffer(buffer);
    }else{
        std:: cout << "Unable to load Magnet.wav!" << std::endl;
    }
}

void Magnet::draw(Interface &interface) {
    interface.drawMagnet(Position,Magnetradius,radius,&sprite);
}

Vector2D Magnet::collideWith(Ball &ball, double collision_time, Manager &manager) {
    Vector2D Acceleration = { 0,0 },farD;
    double ScalarVelocity = VectorNorm(ball.getVelocity());
    farD = VectorDirection( ball.getCenter(),Position);
    if (VectorDistance(ball.getCenter(), Position) <= ball.getRadius() + Magnetradius) {
        Acceleration = farD * ScalarVelocity * MagnetForce;
        sound.play();
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
