#pragma once

struct Vector2D  // Represents a 2D vector
{
    float x = 0;  // The first coordinate
    float y = 0;  // The second coordinate
    Vector2D operator*(float scale) { return Vector2D{x * scale, y * scale}; }  // Scalar multiplication
    Vector2D operator/(float scale) { return Vector2D{x / scale, y / scale}; }  // Scalar division
    Vector2D operator+(float scale) { return Vector2D{x + scale, y + scale}; }  // Scalar addition
    Vector2D operator-(float scale) { return Vector2D{x - scale, y - scale}; }  // Scalar subtraction
    Vector2D operator*(const Vector2D & v) { return Vector2D{x * v.x, y * v.y}; }  // Element-wise multiplication
    Vector2D operator/(const Vector2D & v) { return Vector2D{x / v.x, y / v.y}; }  // Element-wise division
    Vector2D operator+(const Vector2D & v) { return Vector2D{x + v.x, y + v.y}; }  // Element-wise addition
    Vector2D operator-(const Vector2D & v) { return Vector2D{x - v.x, y - v.y}; }  // Element-wise subtraction
    Vector2D & operator*=(const Vector2D & v) { x *= v.x; y *= v.y; return *this; }  // Element-wise multiplication
    Vector2D & operator/=(const Vector2D & v) { x /= v.x; y /= v.y; return *this; }  // Element-wise division
    Vector2D & operator+=(const Vector2D & v) { x += v.x; y += v.y; return *this; }  // Element-wise addition
    Vector2D & operator-=(const Vector2D & v) { x -= v.x; y -= v.y; return *this; }  // Element-wise subtraction
};

enum FlipperType { LEFT, RIGHT };

// Should be replaced by a config file!
#define GAME_WIDTH 720
#define GAME_HEIGHT 1000
#define BALL_RADIUS 10
#define INITIAL_CENTER {400, 400}
<<<<<<< HEAD
#define INITIAL_VELOCITY {-700, 300}
=======
#define INITIAL_VELOCITY {-700, 500}
>>>>>>> master
#define FLIPPER_MAJOR_RADIUS 10
#define FLIPPER_MINOR_RADIUS 5
#define FLIPPER_LENGTH 50
#define FLIPPERS_DISTANCE FLIPPER_LENGTH
#define FLIPPERS_ANGLE_EXTENDED 50
#define FLIPPERS_ANGLE_NORMAL -30
#define FLIPPERS_ROTATE_VELOCITY 1000