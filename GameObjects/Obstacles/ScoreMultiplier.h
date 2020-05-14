#pragma once

#include "Bumper.h"
#include "../../Defs.h"

class ScoreMultiplier : public Bumper
{
private:
    Vector2D Center;
    double Radius;
public:
	ScoreMultiplier(Vector2D pos, double rad);
	Vector2D collideWith(Ball& ball, double collision_time, Manager& manager) override;
	void draw(Interface& interface) override;
};
