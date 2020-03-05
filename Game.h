#pragma once

#include <chrono>
using namespace std::chrono;

#include <string>
using namespace std;

#include "Interface.h"
#include "Defs.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Obstacles/Wall.h"
#include "GameObjects/Flipper.h"
#include "GameObjects/Obstacles/SpriteWalls.h"

// Represents a game, keeps track of everything relevant to the game and delegates the tasks to their proper objects
class Game
{
private:
    high_resolution_clock::time_point last_frame;  // Time point of the last rendered frame
    Interface interface;  // An object representing the game interface
    bool exit, left, right;  // Flags about the user's current controls

    Ball ball;  // The ball (obviously :D)
    Flipper leftFlipper, rightFlipper;  // The right and left flippers
    Wall leftWall, rightWall;  // This line should be replaced by an array of obstacles
    SpriteWalls walloutsite=SpriteWalls("Assets/Sprites - Test/WallOutside.png",{-74,-70});
    sf::Sprite sprite=walloutsite.GetSprite();

public:
    Game();
    void readInterfaceInput();
    void simulate();
    void updateInterfaceOutput();
    bool exited();
};
