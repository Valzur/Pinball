#pragma once

#include "Obstacles/Obstacle.h"
#include <cmath>
#include "../Defs.h"
#include "../Utility/CollisionDetection.h"

using namespace std;

// Represents a (controllable) flipper
class Flipper: public Obstacle
{
private:
    FlipperType type;  // Left or right flipper
    Vector2D center;  // Center of rotation
    double length;  // Flipper length
    double angle;  // Angle of rotation
    const float ExtendedAngle;
    const float NormalAngle;
    const float Velocity;
    double majorRadius;  // The radius of the rotation end
    double minorRadius;  // The radius of the other end
    double ImpulseMultiplier; //to be used to accelerate the collision if the flipper was moving at the time of collision.
    bool Left=false,Right=false;
public:
    // The angle should probably be removed from the constructor after adding the controls
    Flipper(FlipperType type, Vector2D center, double length, double angle, double majorRadius, double minorRadius, double NormalAngle, double ExtendedAngle,double Velocity);

    Vector2D collideWith(Ball & ball, double collision_time, Manager & manager) override;
    void draw(Interface & interface) override;
    void RotateFlipper(double a, double time);
    void MoveFlipper(bool left, bool right, double delta_time);
};
