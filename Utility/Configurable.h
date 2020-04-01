#pragma once
#include <fstream>
#include "AudioManager.h"
#include "../GameObjects/Ball.h"
#include "../GameObjects/Flipper.h"
#include "../GameObjects/Manager.h"
#include "../GameObjects/Obstacles/Bumper.h"
#include "../GameObjects/Obstacles/Wall.h"
#include "../GameObjects/Obstacles/PopBumper.h"

using namespace std;

class Configurable {
private:
    fstream file;
    int BallsNo,PopBumpersNo,WallsNo,FlippersNo,Progress,Total;
    Vector2D Acceleration={0,0};
public:
    //Pointers to everything in the game
    Ball **pBalls;
    Flipper **pFlippers;
    PopBumper **pPopBumpers;
    Wall **pWalls;
    //Those only need one instance.
    Manager *pManager;
    AudioManager *pAudioManager;

    //Reading Functions
    void ReadBalls(string TextPath);
    void ReadFlippers(string TextPath);
    void ReadPopBumpers(string TextPath);
    void ReadWalls(string TextPath);
    void ReadManager(string TextPath);
    void ReadAudioManager(string TextPath);

    //Drawing Functions
    void DrawBalls(Interface & interface);
    void DrawFlippers(Interface & interface);
    void DrawWalls(Interface & interface);
    void DrawPopBumpers(Interface & interface);

    //Collision Functions
    void FlippersCollision(Ball & ball, float collision_time, Manager & manager);
    void PopBumpersCollision(Ball & ball, float collision_time, Manager & manager);
    void BallsCollision(Ball & ball, float collision_time, Manager & manager);
    void WallsCollision(Ball & ball, float collision_time, Manager & manager);

    //Read and draw everything once (returns progress out of 100)
    void LoadEverything();
    void DrawEverything(Interface & interface);
    void Collision(Ball & ball, float collision_time);

};