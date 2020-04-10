#include <iostream>
#include "Game.h"

#define GRAVITY 400.0f

Game::Game(): manager(0,3), audioManager(true,("Audio/NEFFEX - Dangerous [Copyright Free].ogg"))
{
    last_frame = high_resolution_clock::now();
    exit = left = right =space = false;
}

void Game::readInterfaceInput()
{
    interface.getControls(exit, left, right,space);
}

void Game::simulate()
{
    //Load everything :"D
    if(!Loaded) {
        interface.LoadGraphics();
        InstantiateObstacles();
    }
    // Measuring time elapsed in-between frames
    high_resolution_clock::time_point this_frame = high_resolution_clock::now();
    duration<float> time_span = duration_cast<duration<float>>(this_frame - last_frame);
    last_frame = this_frame;
    float delta_time = time_span.count();  // Delta time in seconds

    //Update fps
    interface.setFPS("FPS: " + to_string(1.0/delta_time));

    //Pls
    ActivateBalls(space);
    FlippersMotion(left, right,delta_time);
    CollisionCheck(delta_time,manager);
    MoveBalls(delta_time);
    //Pls

    if(!Loaded)
        Loaded=true;
}

void Game::updateInterfaceOutput()
{
    interface.clear();
    if(!Lost) {
        //Load things
        interface.drawBackground();
        interface.loadExternalFrame(1,-10.0f);
        interface.loadExternalFrame(1,10.0f);
        interface.loadExternalFrame(0,10.0f);
        interface.drawSpeedBoasterLeft();
        interface.drawSpeedBoasterRight();

        //Pls
        DrawDrawables();
        manager.Updategame(interface);
        //Pls

        //FPS UPDATE
        interface.drawFPS();
    }else{
        manager.EndGame(interface);
    }
        interface.display();
}


bool Game::exited()
{
    return exit;
}

void Game::GameOver(bool lost) {
    Lost=lost;
}

void Game::InstantiateObstacles() {
    file.open("../Configurations/Obstacles.txt");
    if(file.is_open()){
        string Choice="0";
        while(Choice!="END") {
            file >> Choice;
            if (Choice=="PORTAL") {
                ReadPortals(file);
            } else if (Choice=="BALL") {
                ReadBalls(file);
            } else if (Choice=="FLIPPER") {
                ReadFlippers(file);
            } else if (Choice=="loadInternalFrameRight") {

            } else if (Choice=="loadInternalFrameLeft") {

            } else if (Choice=="POPBUMPERS"){
                ReadPopBumpers(file);
            } else if(Choice=="MAGNET"){
                ReadMagnets(file);
            }
        }
    }else{
        cout << "Error, unable to open Obstacles file!" << endl;
    }
}

void Game::AddObstacle(Obstacle *obstacle) {
    Obstacle **pTemp=new Obstacle*[ObstaclesNo+1];
    //Everything is copied onto a temporary array
    for (int i = 0; i <ObstaclesNo; i++) {
        pTemp[i]=pObstacles[i];
    }
    pTemp[ObstaclesNo]=obstacle;
    ObstaclesNo++;
    pObstacles=new Obstacle*[ObstaclesNo];
    for (int j = 0; j <ObstaclesNo; j++) {
        pObstacles[j]=pTemp[j];
    }
    delete[]pTemp;
}

void Game::ReadBalls(fstream &file) {
    Vector2D velocity, center;
    string IsMain, Trash;
    float radius;
    int BallsNo;
    file >> BallsNo;
    for (int i = 0; i < BallsNo; ++i) {
        //Center first
        file >> Trash;
        file >> center.x;
        file >> center.y;
        //Radius second
        file >> Trash;
        file >> radius;
        //Velocity third
        file >> Trash;
        file >> velocity.x;
        file >> velocity.y;
        //If main last
        file >> Trash;
        file >> IsMain;
        if (IsMain == "YES") {
            AddBall(new Ball( center, radius, velocity, true));
            AddDrawable(pBalls[i]);
        } else if (IsMain == "NO") {
            AddBall(new Ball( center, radius, velocity, false));
            AddDrawable(pBalls[i]);
        }
    }
}

void Game::ReadFlippers(fstream &file) {
    int FlippersNo = 0;
    file >> FlippersNo;

    for (int i = 0; i < FlippersNo; i++) {
        Vector2D Center;
        string Flippertype, Trash;
        float length, angle, MajorRadius, MinorRadius, NormalAngle, ExtendedAngle, Velocity;
        file >> Trash;
        file >> Flippertype;
        file >> Trash;
        file >> Center.x;
        file >> Center.y;
        file >> Trash;
        file >> length;
        file >> Trash;
        file >> angle;
        file >> Trash;
        file >> MajorRadius;
        file >> Trash;
        file >> MinorRadius;
        file >> Trash;
        file >> NormalAngle;
        file >> Trash;
        file >> ExtendedAngle;
        file >> Trash;
        file >> Velocity;

        if (Flippertype == "RIGHT") {
            AddObstacle(new Flipper(FlipperType::RIGHT, Center, length, angle, MajorRadius, MinorRadius, NormalAngle,
                                    ExtendedAngle, Velocity));
            AddDrawable(pObstacles[ObstaclesNo-1]);
        } else if (Flippertype == "LEFT") {
            AddObstacle(new Flipper(FlipperType::LEFT, Center, length, angle, MajorRadius, MinorRadius, NormalAngle,
                                    ExtendedAngle, Velocity));
            AddDrawable(pObstacles[ObstaclesNo-1]);
        }
    }
}

void Game::ReadPopBumpers(fstream &file) {
    Vector2D center;
    float radius;
    int PopBumpersNo;
    string Trash;
    file >> PopBumpersNo;

    for (int i = 0; i <PopBumpersNo; i++) {
        file >> Trash;
        file >> center.x;
        file >> center.y;
        file >> Trash;
        file >> radius;
        AddObstacle(new PopBumper(center,radius));
        AddDrawable(pObstacles[ObstaclesNo-1]);
    }
}

void Game::CollisionCheck(float collision_time, Manager & manager) {
    for (int i = 0; i < BallsNo; i++) {
        pBalls[i]->setAcceleration({0,-400});
        for (int j = 0; j <ObstaclesNo; j++) {
            pBalls[i]->setAcceleration(pBalls[i]->getAcceleration()+pObstacles[j]->collideWith(*pBalls[i],collision_time,manager));
        }
        //With other balls as well.
        for (int k = 0; k <BallsNo; k++) {
            pBalls[i]->setAcceleration(pBalls[i]->getAcceleration()+pBalls[k]->collideWith(*pBalls[i],collision_time,manager));
        }
    }
}

void Game::DrawDrawables() {
    for (int i = 0; i <DrawablesNo; i++) {
        pDrawn[i]->draw(interface);
    }
}

void Game::ActivateBalls(bool space) {
    for (int i = 0; i <BallsNo ;i++) {
        if(pBalls[i]->getisMain())
            pBalls[i]->Activate(space);
    }
}

void Game::FlippersMotion(bool left, bool right, float delta_time) {
    Flipper *pFlipper;
    for (int i = 0; i <ObstaclesNo; i++) {
        pFlipper= dynamic_cast<Flipper*>(pObstacles[i]);
        if(pFlipper!=NULL){
            pFlipper->MoveFlipper(left, right, delta_time);
        }
    }
}

void Game::ReadWalls(fstream &file) {
    //Nope.
}

void Game::ReadPortals(fstream &file) {
    string Trash;
    double radius;
    Vector2D Pos1,Pos2;
    int PortalsNo;
    file >> PortalsNo;
    for (int i = 0; i <PortalsNo; i++) {
        file >> Trash;
        file >> Pos1.x;
        file >> Pos1.y;
        file >> Trash;
        file >> Pos2.x;
        file >> Pos2.y;
        file >> Trash;
        file >> radius;
        AddObstacle(new Portal(Pos1,Pos2,radius));
        AddDrawable(pObstacles[ObstaclesNo-1]);
    }
}

void Game::MoveBalls(float time) {
    for (int i = 0; i <BallsNo; i++) {
        pBalls[i]->move(time);
        manager.ValueUpdate(*pBalls[i],Lost);
    }
}

void Game::AddDrawable(Drawn *drawn){
    Drawn **pTemp=new Drawn*[DrawablesNo+1];
    //Everything is copied onto a temporary array
    for (int i = 0; i <DrawablesNo; i++) {
        pTemp[i]=pDrawn[i];
    }
    pTemp[DrawablesNo]=drawn;
    DrawablesNo++;
    pDrawn=new Drawn*[DrawablesNo];
    for (int j = 0; j <DrawablesNo; j++) {
        pDrawn[j]=pTemp[j];
    }
    delete[]pTemp;
}

void Game::AddBall(Ball *ball) {
    Ball **pTemp=new Ball*[BallsNo+1];
    //Everything is copied onto a temporary array
    for (int i = 0; i <BallsNo; i++) {
        pTemp[i]=pBalls[i];
    }
    pTemp[BallsNo]=ball;
    BallsNo++;
    pBalls=new Ball*[BallsNo];
    for (int j = 0; j <BallsNo; j++) {
        pBalls[j]=pTemp[j];
    }
    delete[]pTemp;
}

void Game::ReadMagnets(fstream& file) {
    string Trash;
    Vector2D Position;
    double MagnetRadius,radius;
    int MagnetNo;
    file >> MagnetNo;
    for (int i = 0; i <MagnetNo; i++) {
        file >> Trash;
        file >> Position.x;
        file >> Position.y;
        file >> Trash;
        file >> MagnetRadius;
        file >> Trash;
        file >> radius;
        AddObstacle(new Magnet(Position,MagnetRadius,radius));
        AddDrawable(pObstacles[ObstaclesNo-1]);
    }
}
