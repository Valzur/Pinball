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
#include "GameObjects/Obstacles/Bumper.h"
#include "GameObjects/Manager.h"
#include "Utility/AudioManager.h"

// Represents a game, keeps track of everything relevant to the game and delegates the tasks to their proper objects
class Game
{
private:
    high_resolution_clock::time_point last_frame;  // Time point of the last rendered frame
    Interface interface;  // An object representing the game interface
    bool exit, left, right,space;  // Flags about the user's current controls
    bool Lost=false;

    bool Loaded= false;

    AudioManager audioManager;
    Manager manager;

    Ball ball, captive1,captive2;  // The ball (obviously :D)
    Flipper leftFlipper, rightFlipper;  // The right and left flippers
    Wall leftWall, rightWall,upperWall;  // This line should be replaced by an array of obstacles
    Bumper bumper1, bumper2;
    //SpriteWalls walloutsite=SpriteWalls("Assets/Sprites - Test/WallOutside.png",{-74,-70});
    //sf::Sprite sprite=walloutsite.GetSprite();
public:
    Game();
    void readInterfaceInput();
    void simulate();
    void updateInterfaceOutput();
    bool exited();
    void GameOver(bool lost);

    void DoBallCollision(Ball & inball,float delta_time,int isMain);
};
