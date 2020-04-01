#pragma once
#include "Bumper.h"


class PopBumper : public Bumper{
private:

public:
    PopBumper(Vector2D pos, float rad);
    void draw(Interface & interface) override;
    Vector2D collideWith(Ball& ball, float collision_time, Manager & manager)override;
};


