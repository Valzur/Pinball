#include "Bumper.h"

double Bumper::GetRadius() {
    return radius;
}

Bumper::Bumper(Vector2D pos, double rad, BumperType type): type(type) {
    position=pos;
    radius=rad;
    bscore=0;
}

Vector2D Bumper::GetPosition(){
    return position;
}

void Bumper::setScorepoints(int x) {
    bscore = x;
}

BumperType Bumper::GetType() {
    return type;
}
