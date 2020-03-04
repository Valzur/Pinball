
#include "SpriteWalls.h"

void SpriteWalls::LoadTexture(string path) {
    if (!texture.loadFromFile(path)){
    cout<<"Error, Couldn't load texture.."<<endl;
    }else{
        sprite.setTexture(texture);
    }
}

void SpriteWalls::SetPosition(Vector2D pos) {
    sprite.setPosition(pos.x,pos.y);
}

sf::Sprite SpriteWalls::GetSprite() {
    return sprite;
}

SpriteWalls::SpriteWalls(string TexturePath, Vector2D SpritePosition) {
    if (!texture.loadFromFile(TexturePath)){
        cout<<"Error, Couldn't load texture.."<<endl;
    }else{
        sprite.setTexture(texture);
        sprite.setPosition(SpritePosition.x,SpritePosition.y);
        sprite.setColor(sf::Color::Black);
    }
}


