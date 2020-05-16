#pragma once

#include <iostream>
#include "Obstacle.h"
#include <cmath>
#include "../Manager.h"
#include "../../Defs.h"
#include "../../Utility/CollisionDetection.h"

class Switch : public Obstacle {
private:
	Vector2D Center;
	double Length;
	bool collidedLastFrame,Used=false,Direction= false;
public:
	explicit Switch(Vector2D Center,double Length);

	void draw(Interface& interface)override;
    Vector2D collideWith(Ball& ball, double collision_time, Manager& manager) override;
};