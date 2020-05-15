#include "Bullseye.h"

Bullseye::Bullseye(Vector2D Center, double Length, bool isVertical):Center(Center), Length(Length),isVertical(isVertical) {}

void Bullseye::draw(Interface &interface) {
    interface.drawBullseye(Center,Length,width,isVertical);
}

Vector2D Bullseye::collideWith(Ball &ball, double collision_time, Manager &manager) {
    Vector2D Acceleration{0,0};
    if(isVertical){

    }else {
        if ( ball.getCenter().y - Center.y < ball.getRadius() + width ) {
            if ((ball.getCenter().x > Center.x - Length / 6.0) & (ball.getCenter().x > Center.x + Length / 6.0)) {
                //Ace position

                manager.addScore(2500);
            } else if ((ball.getCenter().x > Center.x - Length / 3.0) & (ball.getCenter().x > Length / 3.0)) {
                //Expert position

                manager.addScore(1000);
            } else if ((ball.getCenter().x > Center.x - Length / 2.0) & (ball.getCenter().x > Length / 2.0)) {
                //Novice Position

                manager.addScore(500);

            }
        }
    }
    return Acceleration;
}
