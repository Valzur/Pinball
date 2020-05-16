#include "Switch.h"
#include <cmath>

using namespace std;

Switch::Switch(Vector2D Center,double Length) :collidedLastFrame(false), Center(Center),Length(Length) {}

void Switch::draw(Interface& interface)
{
	interface.drawSwitch(Center, Length,Used);
}

Vector2D Switch::collideWith(Ball &ball, double collision_time, Manager &manager) {
    if(InRange(ball.getCenter().x,Center.x + Length/2.0,Center.x - Length/2.0)){
        if(InRange(ball.getCenter().y, Center.y + 5, Center.y - 5)){
            if(Used){
                if(collidedLastFrame){
                    //Nothing
                    collidedLastFrame = false;
                }else{
                    collidedLastFrame = true;
                    ball.setVelocity({ball.getVelocity().x,-ball.getVelocity().y});
                }
            }else{
                if(collidedLastFrame){
                    Used = (Direction != ball.getVelocity().y > 0);
                    collidedLastFrame = !Used;
                }else{
                    collidedLastFrame = true;
                    Direction = ball.getVelocity().y > 0;
                }
            }
        }
    }
    return {0,0};
}
