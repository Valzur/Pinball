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
#include "GameObjects/Obstacles/Kicker.h"
#include "GameObjects/Obstacles/Bumper.h"
#include "GameObjects/Obstacles/InternalFrames.h"
#include "GameObjects/Manager.h"
#include "Utility/AudioManager.h"
#include "Utility/Configurable.h"
#include "GameObjects/Obstacles/Portal.h"
#include "GameObjects/Obstacles/ExternalFrame.h"
#include "GameObjects/Obstacles/Gate.h"
#include "GameObjects/Obstacles/Magnet.h"
#include <fstream>
#include "GameObjects/Obstacles/SpeedBooster.h"
#include "GameObjects/Obstacles/VibraniumBumper.h"
#include "GameObjects/Obstacles/ThrustBumper.h"
#include "GameObjects/Obstacles/PopBumper.h"
#include "GameObjects/Obstacles/ScoreMultiplier.h"
#include "GameObjects/Obstacles/Switch.h"
#include "GameObjects/Obstacles/Collectable.h"
#include "GameObjects/Obstacles/Lane.h"
#include "GameObjects/Obstacles/Ramp.h"

// Represents a game, keeps track of everything relevant to the game and delegates the tasks to their proper objects
class Game
{
private:
    fstream file;
    high_resolution_clock::time_point last_frame;  // Time point of the last rendered frame
    Interface interface;  // An object representing the game interface
    bool exit, left, right,space;  // Flags about the user's current controls
    bool Lost=false;

    Manager manager;
    AudioManager audioManager;

    bool Loaded= false;

    //Pls work
    Ball **pBalls;
    Obstacle **pObstacles;
    Drawn** pDrawn;
    int ObstaclesNo=0,BallsNo=0,DrawablesNo=0;
    //Debug position
    string Debug;
    string scoreText,livesText;
public:
    Game();
    void readInterfaceInput();
    void simulate();
    void updateInterfaceOutput();
    bool exited();
    void GameOver(bool lost);

    //ReadEverything
    void InstantiateObstacles();

    void DrawDrawables();
    void CollisionCheck(float collision_time, Manager & manager);

    //Utility
    void AddObstacle(Obstacle *obstacle);
    void AddDrawable(Drawn *drawn);
    void AddBall(Ball * ball);

    //Reading
    void ReadBalls(fstream &file);
    void ReadFlippers(fstream &file);
    void ReadBumpers(fstream &file);
    void ReadWalls(fstream& file);
    void ReadPortals(fstream&file);
    void ReadMagnets(fstream&file);
    void ReadInternalFrame(fstream& file);
    void ReadGates(fstream& file);
    void ReadKickers(fstream& file);
    void ReadSwitchs(fstream& file);
    void ReadCollectables(fstream& file);
    void ReadSpeedBoosters(fstream& file);
    void ReadLanes(fstream& file);
    void ReadRamps(fstream& file);

    void ActivateBalls(bool space);
    void FlippersMotion(bool left, bool right, float delta_time);
    void MoveBalls(double time);

    void DebugMode(Interface& interface);
    void UIElements(Interface& interface);
};
