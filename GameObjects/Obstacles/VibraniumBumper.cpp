#include "VibraniumBumper.h"

VibraniumBumper:: VibraniumBumper(Vector2D pos, double rad): Bumper(pos,rad,  VIBRANIUM){
    if(buffer.loadFromFile("../Assets/SFX/Vibranium.wav")){
        sound.setBuffer(buffer);
    }else{
        std:: cout << "Unable to load Vibranium.wav!" << std::endl;
    }
}
void VibraniumBumper::draw(Interface& interface) {
    interface.drawVibraniumBumper(GetPosition(), GetRadius(),Hit);
}

Vector2D VibraniumBumper::collideWith(Ball& ball, double collision_time, Manager& manager) {
    if (ball.getRadius() + GetRadius() >= VectorDistance(ball.getCenter(), GetPosition())) {
        ball.setVelocity({ 0,0 });
        sound.play();
        manager.addScore(-1);
    }
    return {0,0};
}

