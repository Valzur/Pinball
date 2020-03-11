#include "Defs.h"

double VectorDistance(Vector2D vector1, Vector2D vector2){
    double distance=pow((pow(vector1.x-vector2.x,2)+pow(vector1.y-vector2.y,2)),0.5);
    return distance;
}

double VectorNorm(Vector2D vector){
    double Norm=pow((pow(vector.x,2)+pow(vector.y,2)),0.5);
    return Norm;
}

Vector2D VectorDirection(Vector2D vector1,Vector2D vector2){
    Vector2D direction={vector2.x-vector1.x,vector2.y-vector2.y};
    direction=direction/VectorNorm(direction);
    return direction;
}