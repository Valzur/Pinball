#include"ScoreMultiplier.h"
using namespace std;

ScoreMultiplier::ScoreMultiplier(Vector2D pos, double rad) : Bumper(pos, rad, SCOREM) {
	setScorepoints(0);
	Center=pos;
	Radius=rad;
    if(buffer.loadFromFile("../Assets/SFX/ScoreMultiplier.wav")){
        sound.setBuffer(buffer);
    }else{
        std:: cout << "Unable to load ScoreMultiplier.wav!" << std::endl;
    }
}
	
Vector2D ScoreMultiplier::collideWith(Ball & ball, double collision_time, Manager & manager){
    Vector2D Acceleration = CircleCollision(ball,Center,Radius,collision_time);

    if(Acceleration==Vector2D{0,0}){
        if(Hit &(hitTimer>0))
            hitTimer-=collision_time;
        else {
            hitTimer=FlashTimer;
            Hit=false;
        }
    }else{
        Hit=true;
        manager.addScore(400);
        manager.MultiplyScore(1.5);
        sound.play();
        ball.setVelocity(Acceleration*collision_time);
    }

    return {0,0};
}

void ScoreMultiplier::draw(Interface& interface) {
    interface.drawBumper(Center,Radius, SCOREM,Hit);
}