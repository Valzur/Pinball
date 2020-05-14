#pragma once

#include <iostream>
#include "Obstacle.h"
using namespace std;

class SpriteWalls: public Obstacle {
private:
    sf::Texture texture;
    Vector2D position;
    sf::Sprite sprite;
public:
    //Constructors
    SpriteWalls(string TexturePath, Vector2D SpritePosition);

    //Configurations
    void LoadTexture(string path);
    void SetPosition(Vector2D pos);
    sf::Sprite GetSprite();
    void draw(Interface & interface) override=0;
    Vector2D collideWith(Ball & ball, double collision_time, Manager & manager) override=0;

};



