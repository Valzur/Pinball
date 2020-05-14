#include "Switch.h"
#include <cmath>

using namespace std;

Switch::Switch(Vector2D position) :collidedLastFrame(false), position(position) {}

void Switch::draw(Interface& interface)
{
	interface.drawSwitch(position);
}

Vector2D Switch::collideWith(Ball &ball, double collision_time, Manager &manager) {
    return {0,0};
}
