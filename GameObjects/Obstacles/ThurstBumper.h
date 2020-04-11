#pragma once
#include "Bumper.h"
#include "../../Defs.h"

class ThurstBumper : public Bumper {
private:

public:
    ThurstBumper(Vector2D pos, float rad);
    void draw(Interface& interface) override;
    Vector2D collideWith(Ball& ball, float collision_time, Manager& manager)override;
};


