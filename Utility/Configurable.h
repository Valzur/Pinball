#pragma once
#include <fstream>
#include "AudioManager.h"
#include "../GameObjects/Ball.h"
#include "../GameObjects/Flipper.h"
#include "../GameObjects/Manager.h"
#include "../GameObjects/Obstacles/Bumper.h"
#include "../GameObjects/Obstacles/Wall.h"

using namespace std;

class Configurable {
private:
    fstream file;
public:
    //Pointers to everything in the game
    Ball **pBalls;
    Flipper **pFlippers;
    Bumper **pBumpers;
    Wall **pWalls;
    //Those only need one instance.
    Manager *Manager;
    AudioManager *audioManager;

    //Reading Functions
    void ReadBalls(string TextPath);
    void ReadFlippers(string TextPath);
    void ReadBumpers(string TextPath);
    void ReadWalls(string TextPath);
    void ReadManager(string TextPath);
    void ReadAudioManager(string TextPath);

    //Read everything once (returns progress out of 100)
    float Load();

};

