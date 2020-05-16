//
// Created by anon on 4/10/20.
//

#include "Wall.h"

Wall::Wall(bool isVertical, float Position)
{

}

void Wall::draw(Interface &interface)
{
    interface.drawWall(isVertical, Position);

}

Vector2D Wall::collideWith(Ball &ball, double collision_time, Manager &manager)
{
    if(isVertical) {
        if (!collidedLastFrame && abs(Position - ball.getCenter().x) < ball.getRadius()) {
            collidedLastFrame = true;

            if(ball.getCenter().x>GAME_WIDTH-ball.getRadius())
                ball.setCenter({GAME_WIDTH-ball.getRadius(), ball.getCenter().y});

            if(ball.getCenter().x<ball.getRadius())
                ball.setCenter({0 + ball.getRadius(), ball.getCenter().y});

            return Vector2D{ball.getVelocity().x * -1, 0} / collision_time;
        } else {
            collidedLastFrame = false;
            return Vector2D{0, 0};
        }
    }else{
        if (!collidedLastFrame && abs(Position - ball.getCenter().y) < ball.getRadius()) {
            collidedLastFrame = true;

            return Vector2D{0, ball.getVelocity().y * -1} / collision_time;
        } else {
            collidedLastFrame = false;
            return Vector2D{0, 0};
        }
    }
}
