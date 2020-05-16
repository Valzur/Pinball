#pragma once

#include "../Drawable.h"
#include "../Collidable.h"
#include "../../Utility/AudioManager.h"

// An abstract class representing an obstacle
class Obstacle: public Drawn, public Collidable, public AudioManager{
};
