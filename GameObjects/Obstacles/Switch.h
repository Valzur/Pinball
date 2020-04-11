#pragma once

#include <iostream>
#include "Obstacle.h"
#include <cmath>
#include "../Manager.h"
#include "../../Defs.h"

class Switch : public Obstacle {
private:
	Vector2D position;
	bool collidedLastFrame; //still need to implement how it's going to collide w ball
public:
	Switch(Vector2D position);

	void draw(Interface& interface);
    Vector2D collideWith(Ball& ball, float collision_time, Manager& manager) override;
};