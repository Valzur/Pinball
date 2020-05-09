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

        //Pls
        DrawDrawables();
        manager.Updategame(interface);
        //Pls

        //Debug
        for (int i = 0; i < BallsNo; i++) {
            if(pBalls[i]->getisMain()){
                Debug="X: " + to_string(pBalls[i]->getCenter().x) + " Y: " + to_string(pBalls[i]->getCenter().y);
            }
        }
        interface.drawText(Debug,30,sf::Color::Black,{400,900});

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
            } else if (Choice=="INTERNALFRAME") {
                ReadInternalFrame(file);
            } else if (Choice=="KICKER") {
                ReadKickers(file);
            } else if (Choice=="BUMPER"){
                ReadBumpers(file);
            } else if (Choice=="MAGNET"){
                ReadMagnets(file);
            } else if (Choice=="KICKER"){
                ReadKickers(file);
            } else if (Choice=="SWITCH"){
                ReadSwitchs(file);
            } else if (Choice=="COLLECTABLE"){
                ReadCollectables(file);
            } else if (Choice=="SPEEDBOOSTER"){
                ReadSpeedBoosters(file);
            } else if (Choice=="GATE"){
                ReadGates(file);
            }
        }
        file.close();
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

void Game::ReadBumpers(fstream &file) {
    Vector2D position;
    float radius;
    int bumpersNo, type;
    string trash;
    file >> bumpersNo;
    for (int i = 0; i < bumpersNo; i++) {
        file >> trash;
        file >> position.x;
        file >> position.y;
        file >> trash;
        file >> radius;
        file >> trash;
        file >> type;
        if (type == 0) {
            AddObstacle(new PopBumper(position, radius));
            AddDrawable(pObstacles[ObstaclesNo-1]);
        } else if (type == 1) {
            AddObstacle(new ThrustBumper(position, radius));
            AddDrawable(pObstacles[ObstaclesNo-1]);
        } else if (type == 2) {
            AddObstacle(new VibraniumBumper(position, radius));
            AddDrawable(pObstacles[ObstaclesNo-1]);
        } else if (type == 3) {
            AddObstacle(new ScoreMultiplier(position, radius));
            AddDrawable(pObstacles[ObstaclesNo-1]);
        }
    }
}

void Game::CollisionCheck(float collision_time, Manager & manager) {
    for (int i = 0; i < BallsNo; i++) {
        pBalls[i]->setAcceleration({0,400});
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

void Game::MoveBalls(double time) {
    for (int i = 0; i <BallsNo; i++) {
        pBalls[i]->move(time,manager,Lost);
        pBalls[i]->UpdateBoost(time);
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
    for (int i = 0; i <MagnetNo; i++)
    {
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

void Game::ReadInternalFrame(fstream& file)
{
    string Trash;
    float is45,isLeft,
    Diameter,LineXCoordinate
    ,LineYCoordinate,InclinationAngle
    ,setPositionX,setPositionYRation;
    int NoFrame;
    file >> NoFrame;
    for (int i = 0; i <NoFrame; i++)
    {
        file >> Trash;
        file >> is45;
        file >> Trash;
        file >> isLeft;
        file >> Trash;
        file >> Diameter;
        file >> Trash;
        file >> LineXCoordinate;
        file >> Trash;
        file >> LineYCoordinate;
        file >> Trash;
        file >> InclinationAngle;
        file >> Trash;
        file >> setPositionX;
        file >> Trash;
        file >> setPositionYRation;
        AddObstacle(new InternalFrames(FloatToBool(is45),FloatToBool(isLeft),Diameter,
                LineXCoordinate,LineYCoordinate,InclinationAngle,setPositionX,setPositionYRation));
        AddDrawable(pObstacles[ObstaclesNo-1]);
    }
}

void Game::ReadGates(fstream& file){
    string Trash;
    float length,width,x,y;
    int GatesNo;

    file >> GatesNo;
    for (int i = 0; i <GatesNo; i++) {
        file >> Trash;
        file >> x;
        file >> y;
        file >> Trash;
        file >> length;
        file >> Trash;
        file >> width;
        AddObstacle(new Gate(x,y,length,width));
        AddDrawable(pObstacles[ObstaclesNo-1]);
    }

}

void Game::ReadKickers(fstream &file)
{
    string Trash;
    float x1,y1,x2,y2,x3,y3;
    int NoFrame=0;
    file >> NoFrame;
    for (int i = 0; i <NoFrame; i++) {
        file >> Trash;
        file >> x1;
        file >> Trash;
        file >> y1;
        file >> Trash;
        file >> x2;
        file >> Trash;
        file >> y2;
        file >> Trash;
        file >> x3;
        file >> Trash;
        file >> y3;
        AddObstacle(new Kicker(x1, x2, x3, y1, y2, y3));
        AddDrawable(pObstacles[ObstaclesNo-1]);
    }
}

void Game::ReadSwitchs(fstream &file) {
    Vector2D position;
    string trash;
    int SwitchNo;
    file >> SwitchNo;
    for (int i = 0; i <SwitchNo; i++) {
        file >> trash;
        file >> position.x;
        file >> position.y;
        AddObstacle(new Switch(position));
        AddDrawable(pObstacles[ObstaclesNo-1]);
    }
}

void Game::ReadCollectables(fstream &file) {
    string Letter,Trash;
    float radius;
    int CollectablesNo;
    Vector2D Center;

    file >> CollectablesNo;
    for (int i = 0; i <CollectablesNo; i++) {
        file >> Trash;
        file >> Center.x;
        file >> Center.y;
        file >> Trash;
        file >> radius;
        file >> Letter;
        AddObstacle(new Collectable(radius,Letter,Center));
        AddDrawable(pObstacles[ObstaclesNo-1]);
    }
}

void Game::ReadSpeedBoosters(fstream &file) {
    string Trash;
    int BoostersNo;
    float radius;
    Vector2D Center;

    file >> BoostersNo;
    for (int i = 0; i <BoostersNo; i++) {
        file >> Trash;
        file >> Center.x;
        file >> Center.y;
        file >> Trash;
        file >> radius;
        AddObstacle(new SpeedBooster(radius,Center));
        AddDrawable(pObstacles[ObstaclesNo-1]);
    }
}