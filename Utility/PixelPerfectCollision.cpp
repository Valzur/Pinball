#include "PixelPerfectCollision.h"

Vector2D PixelPerfectCollision::CheckCollision(Ball ball, Sprite sprite) {
    Vector2D Acc={0,0};
    image =sprite.getTexture()->copyToImage();
    size=image.getSize();
    ballPosition=ball.getCenter();
    for (int i = 0; i < size.x; i++) {
        for (int j = 0; j < size.y; j++) {
                if (pow((pow(i+size.x, 2) + pow(j+size.y, 2)), 0.5) <= ball.getRadius()) {
                    Acc = {ballPosition.x - i, ballPosition.y - j};
                    break;
                }
        }
        if (Acc.x!=0 | Acc.y!=0)
            break;
    }
    Acc={-Acc.x,-Acc.y};
    return Acc;
}
