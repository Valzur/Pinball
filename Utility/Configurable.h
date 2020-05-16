#pragma once
#include <fstream>
#include "AudioManager.h"
#include "../GameObjects/Ball.h"
#include "../GameObjects/Flipper.h"
#include "../GameObjects/Manager.h"
#include "../GameObjects/Obstacles/Bumper.h"
#include "../GameObjects/Obstacles/Wall.h"
#include "../GameObjects/Obstacles/PopBumper.h"
#include "../GameObjects/Obstacles/Ramp.h"
#include "../GameObjects/Obstacles/Wall.h"

using namespace std;

class Configurable {
private:
    fstream file;
    int BallsNo,PopBumpersNo,WallsNo,FlippersNo,Progress,Total;
    Vector2D *pAcceleration;
public:
    //Pointers to everything in the game
    Ball **pBalls;
    Flipper **pFlippers;
    PopBumper **pPopBumpers;
    Wall **pWalls;
    //Those only need one instance.
    Manager *pManager;
    AudioManager *pAudioManager;
    Ramp** pInternalFrames;
    Wall** pExternalFrame;


    //Reading Functions
    void ReadBalls(const string& TextPath);
    void ReadFlippers(const string& TextPath);
    void ReadPopBumpers(const string& TextPath);
    void ReadWalls(string TextPath);
    void ReadManager(const string& TextPath);
    void ReadAudioManager(const string& TextPath);

    //Drawing Functions
    void DrawBalls(Interface & interface);
    void DrawFlippers(Interface & interface);
    void DrawWalls(Interface & interface);
    void DrawPopBumpers(Interface & interface);

    //Collision Functions
    Vector2D FlippersCollision(Ball & ball, float collision_time, Manager & manager);
    Vector2D PopBumpersCollision(Ball & ball, float collision_time, Manager & manager);
    Vector2D BallsCollision(Ball & ball, float collision_time, Manager & manager);
    Vector2D WallsCollision(Ball & ball, float collision_time, Manager & manager);

    //Moving flippers
    void FlippersMotion(bool left, bool right, float delta_time);
    void ActivateBalls(bool space);

    //Read and draw everything once (returns progress out of 100)
    void LoadEverything();
    void DrawEverything(Interface & interface);
    void Collision(float collision_time);

};