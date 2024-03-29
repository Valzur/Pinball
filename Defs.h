#pragma once

#include <cmath>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

struct Vector2D  // Represents a 2D vector
{
    double x = 0;  // The first coordinate
    double y = 0;  // The second coordinate
    Vector2D operator*(double scale) { return Vector2D{x * scale, y * scale}; }  // Scalar multiplication
    Vector2D operator/(double scale) { return Vector2D{x / scale, y / scale}; }  // Scalar division
    Vector2D operator+(double scale) { return Vector2D{x + scale, y + scale}; }  // Scalar addition
    Vector2D operator-(double scale) { return Vector2D{x - scale, y - scale}; }  // Scalar subtraction
    Vector2D operator*(const Vector2D & v) { return Vector2D{x * v.x, y * v.y}; }  // Element-wise multiplication
    Vector2D operator/(const Vector2D & v) { return Vector2D{x / v.x, y / v.y}; }  // Element-wise division
    Vector2D operator+(const Vector2D & v) { return Vector2D{x + v.x, y + v.y}; }  // Element-wise addition
    Vector2D operator-(const Vector2D & v) { return Vector2D{x - v.x, y - v.y}; }  // Element-wise subtraction
    Vector2D & operator*=(const Vector2D & v) { x *= v.x; y *= v.y; return *this; }  // Element-wise multiplication
    Vector2D & operator/=(const Vector2D & v) { x /= v.x; y /= v.y; return *this; }  // Element-wise division
    Vector2D & operator+=(const Vector2D & v) { x += v.x; y += v.y; return *this; }  // Element-wise addition
    Vector2D & operator-=(const Vector2D & v) { x -= v.x; y -= v.y; return *this; }  // Element-wise subtraction
    bool operator==(const Vector2D & v){ return x == v.x & y == v.y; } //Equality.
    bool operator!=(const Vector2D & v){ return x != v.x || y != v.y; } //Opposite
    operator sf::Vector2f(){ return {static_cast<float>(x),static_cast<float>(y)}; }
};

double VectorDistance(Vector2D vector1,Vector2D vector2);
double VectorNorm(Vector2D vector);
Vector2D VectorDirection(Vector2D vector1,Vector2D vector2);
double lerp(double a,double b,double t);
double DotProduct(Vector2D u, Vector2D v);

enum FlipperType { LEFT, RIGHT };
enum BumperType{POP,THRUST,VIBRANIUM,SCOREM};
bool FloatToBool(float number);

// Should be replaced by a config file!
#define FPSLimit 240
#define GAME_WIDTH 720
#define WINDOW_WIDTH 1000
#define GAME_HEIGHT 1000

#define INITIAL_CENTER {600, 400}
#define INITIAL_VELOCITY {-900, 600}

//Making life easier <3

#define SpeedBoosterAmount 2.5
#define LaneVelocityMultiplier 2.5
#define FlashTimer 0.3
#define LaneTimer 0.6
#define MagnetForce 3.5
#define PobBumperBoost 0.1
#define ControlTimer 0.1
#define ThrustBumperBoost 1.5
#define PI M_PI
#define ControlFrames 15
#define VibraniumFlash 0.4
#define VelocityControl 1000
#define GlobalWidth 15