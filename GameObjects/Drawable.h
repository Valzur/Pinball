#pragma once

#include "../Interface.h"

// An interface class that should be implemented by any class that has a visual representation
class Drawn
{
public:
    virtual void draw(Interface & interface) = 0;  // Uses the interface object to draw itself
};
