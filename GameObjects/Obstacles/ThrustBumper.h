#pragma once
#include "Bumper.h"
#include "../../Defs.h"

class ThrustBumper : public Bumper {
private:
public:
    ThrustBumper(Vector2D pos, double rad);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager& manager)override;
};


