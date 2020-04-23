#include"ScoreMultiplier.h"
using namespace std;

ScoreMultiplier::ScoreMultiplier(Vector2D pos, float rad) : Bumper(pos, rad, SCOREM) {
	setScorepoints(0);
}
	
Vector2D ScoreMultiplier::collideWith(Ball & ball, float collision_time, Manager & manager)  {
    return {0,0};
}

void ScoreMultiplier::draw(Interface& interface) {
    interface.drawBumper(Bumper::GetPosition(),Bumper::GetRadius(), Bumper::GetType());
}