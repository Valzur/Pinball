#pragma once

#include "Bumper.h"
#include "../../Defs.h"

class ScoreMultiplier : public Bumper
{
private:
public:
	ScoreMultiplier(Vector2D pos, float rad);
	Vector2D collideWith(Ball& ball, float collision_time, Manager& manager) override;
	void draw(Interface& interface) override;

};
