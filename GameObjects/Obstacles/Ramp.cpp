#include "Ramp.h"

void Ramp::draw(Interface &interface) {
    interface.drawRamp(is45, isLeft, Diameter, Size, Angle, x,setPositionYRation);
}

Ramp::Ramp(bool is45, bool isLeft, double Diameter,Vector2D Size,
        double Angle, double x, double setPositionYRation){
    this->is45=is45;
    this->isLeft=isLeft;
    this->Diameter=Diameter;
    this->Size=Size;
    this->Angle=Angle;
    this->x=x;
    this->setPositionYRation=setPositionYRation;
}

Vector2D Ramp::collideWith(Ball &ball, double collision_time, Manager &manager) {
    if(setPositionYRation==0){
        LineCollision(ball,Size.x,Angle,Center);
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
