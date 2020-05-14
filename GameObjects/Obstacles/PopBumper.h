#pragma once
#include "Bumper.h"


class PopBumper : public Bumper{
private:

public:
    PopBumper(Vector2D pos, double rad);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager & manager)override;
};


