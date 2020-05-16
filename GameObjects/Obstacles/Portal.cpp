#include "Portal.h"

void Portal::draw(Interface &interface) {
    interface.drawPortals(Pos1,Pos2,radius);
    if(buffer.loadFromFile("../Assets/SFX/Portal.wav")){
        sound.setBuffer(buffer);
    }else{
        std:: cout << "Unable to load Portall.wav!" << std::endl;
    }
}

Portal::Portal(Vector2D Pos1, Vector2D Pos2, double radius): Pos1(Pos1),Pos2(Pos2),radius(radius) {}

Vector2D Portal::collideWith(Ball &ball, double collision_time, Manager &manager) {
    bool Portal1,Portal2;
    Portal1=BICCollision(ball,Pos1,radius);
    Portal2=BICCollision(ball,Pos2,radius);
    if(Portal1){
        if(!ball.getIsUsedPortal()){
            ball.setCenter(Pos2);
            ball.setUsedPortal(true);
            sound.play();
        }
    }else if(Portal2){
        if(!ball.getIsUsedPortal()){
            ball.setCenter(Pos1);
            ball.setUsedPortal(true);
            sound.play();
        }
    }else{
        ball.setUsedPortal(false);
    }
    return {0,0};
}

