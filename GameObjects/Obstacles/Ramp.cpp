#include "Ramp.h"

void Ramp::draw(Interface &interface) {
    interface.drawRamp(Center,Size,Angle);
}


Vector2D Ramp::collideWith(Ball &ball, double collision_time, Manager &manager) {
        if(FramesTillNextCollision == 0){
            Vector2D Velocity = RectangleCollision(ball,Size.x,Size.y,Angle,Center);
            if(Velocity == Vector2D{0,0}){

            } else {
                ball.setVelocity({Velocity.x,Velocity.y});
                FramesTillNextCollision = ControlFrames;
            }
        } else {
            FramesTillNextCollision--;
        }

    return{0,0};
}

Ramp::Ramp(Vector2D Size, Vector2D Center, double Angle):Size(Size),Center(Center),Angle(Angle) {
    if(buffer.loadFromFile("../Assets/SFX/WallHit.wav")){
        sound.setBuffer(buffer);
    }else{
        std:: cout << "Unable to load Wallhit.wav!" << std::endl;
    }

}
