#include "Wall.h"

Wall::Wall(bool isVertical, Vector2D Center):Center(Center),isVertical(isVertical){
    if(buffer.loadFromFile("../Assets/SFX/WallHit.wav")){
        sound.setBuffer(buffer);
    }else{
        std:: cout << "Unable to load Wallhit.wav!" << std::endl;
    }
}

void Wall::draw(Interface &interface){
    interface.drawWall(Center, isVertical);
}

Vector2D Wall::collideWith(Ball &ball, double collision_time, Manager &manager)
{
    if(isVertical) {
        if (!collidedLastFrame && abs(Center.x - ball.getCenter().x) < ball.getRadius()) {
            collidedLastFrame = true;
            ball.setVelocity({-ball.getVelocity().x,ball.getVelocity().y});
            sound.play();
        } else {
            collidedLastFrame = false;
        }
    }else{
        if (!collidedLastFrame && abs(Center.y - ball.getCenter().y) < ball.getRadius()) {
            collidedLastFrame = true;
            ball.setVelocity({ball.getVelocity().x,-ball.getVelocity().y});
            sound.play();
        } else {
            collidedLastFrame = false;
        }
    }
    return Vector2D{0, 0};
}
