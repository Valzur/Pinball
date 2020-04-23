#pragma once

#include "Obstacles/Obstacle.h"
#include <cmath>
#include "../Defs.h"

using namespace std;

// Represents a (controllable) flipper
class Flipper: public Obstacle
{
private:
    FlipperType type;  // Left or right flipper
    Vector2D center;  // Center of rotation
    float length;  // Flipper length
    float angle;  // Angle of rotation
    const float ExtendedAngle;
    const float NormalAngle;
    const float Velocity;
    float majorRadius;  // The radius of the rotation end
    float minorRadius;  // The radius of the other end
    float ImpulseMultiplier; //to be used to accelerate the collision if the flipper was moving at the time of collision.

public:
    // The angle should probably be removed from the constructor after adding the controls
    Flipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius, float NormalAngle, float ExtendedAngle,float Velocity);

    Vector2D collideWith(Ball & ball, float collision_time, Manager & manager) override;
    void draw(Interface & interface) override;
    void RotateFlipper(float a, float time);
    void MoveFlipper(bool left, bool right, float delta_time);
};
