#pragma once

#include "Obstacle.h"
#include "../../Utility/CollisionDetection.h"

class Magnet:public Obstacle {
private:
    Vector2D Position;
    double Magnetradius,radius;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Magnet(Vector2D Position, double Magnetradius, double radius);

    //Getters
    double getMagnetRadius()const;
    double getRadius()const;
    Vector2D getCenter() const;
    //Setters
    void setMagnetRadius(double magnetRadius);
    void setRadius(double radius);

    Vector2D collideWith(Ball & ball, float collision_time, Manager & manager)override;
    void draw(Interface & interface) override;
};
