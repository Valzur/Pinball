#pragma once
#include "Bumper.h"


class VibraniumBumper : public Bumper {
private:

public:
    VibraniumBumper(Vector2D pos, float rad);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collision_time, Manager& manager)override;
};


