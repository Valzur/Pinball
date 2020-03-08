#pragma once

#include <iostream>
#include "Obstacle.h"
using namespace std;

class SpriteWalls {
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

};



