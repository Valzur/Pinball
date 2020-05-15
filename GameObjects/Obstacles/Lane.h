#pragma once

#include "../../Utility/CollisionDetection.h"
#include "../../Defs.h"

class Lane : public Obstacle{
private:
    double Length,Timer=LaneTimer;
    const double Width;
    Vector2D Center;
    bool Top=false,Bottom=false;
public:
    Lane(double Length, Vector2D Center, double Width=20);

    //Setters
    void SetLength(double Length);
    void SetCenter(Vector2D Center);

    //Getters
    double GetLength() const;
    Vector2D GetCenter() const;

    void draw(Interface& interface)override;
    Vector2D collideWith(Ball & ball, double collision_time, Manager & manager) override;
};

