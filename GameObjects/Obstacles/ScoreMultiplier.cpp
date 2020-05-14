#include"ScoreMultiplier.h"
using namespace std;

ScoreMultiplier::ScoreMultiplier(Vector2D pos, double rad) : Bumper(pos, rad, SCOREM) {
	setScorepoints(0);
}
	
Vector2D ScoreMultiplier::collideWith(Ball & ball, double collision_time, Manager & manager){
    Vector2D Acceleration= CircleCollision(ball,Center,Radius,collision_time);
    if(Acceleration == Vector2D{0,0})
        manager.MultiplyScore(1.5);

    return {0,0};
}

void ScoreMultiplier::draw(Interface& interface) {
    interface.drawBumper(Bumper::GetPosition(),Bumper::GetRadius(), Bumper::GetType());
}