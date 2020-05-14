#pragma once
#include "Bumper.h"


class VibraniumBumper : public Bumper {
private:

public:
    VibraniumBumper(Vector2D pos, double rad);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager& manager)override;
};


