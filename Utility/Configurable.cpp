#include "Configurable.h"

void Configurable::ReadBalls(const string& TextPath) {

    file.open(TextPath);
    if (file.is_open()) {
        Vector2D velocity, center;
        string IsMain, Trash;
        float radius;
        file >> BallsNo;
        pAcceleration=new Vector2D[3];
        pBalls = new Ball *[BallsNo];

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
                pBalls[i] = new Ball( center, radius, velocity, true);
            } else if (IsMain == "NO") {
                pBalls[i] = new Ball( center, radius, velocity, false);
            }
        }
        file.close();
    }else{
        cout << "Error, unable to read Balls file!" << endl;
    }
}

void Configurable::ReadFlippers(const string& TextPath) {
    file.open(TextPath);
    if(file.is_open()){
        file >> FlippersNo;
        pFlippers=new Flipper*[FlippersNo];

        for (int i = 0; i <FlippersNo; i++) {
            Vector2D Center;
            string Flippertype, Trash;
            float length, angle, MajorRadius, MinorRadius,NormalAngle,ExtendedAngle,Velocity;
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
            //Phew, i hope i get no errors after all of this.
            if(Flippertype=="RIGHT") {
                pFlippers[i]=new Flipper(FlipperType::RIGHT,Center,length,angle,MajorRadius,MinorRadius,NormalAngle,ExtendedAngle,Velocity);
            } else if (Flippertype=="LEFT"){
                pFlippers[i]=new Flipper(FlipperType::LEFT,Center,length,angle,MajorRadius,MinorRadius,NormalAngle,ExtendedAngle,Velocity);
            }
        }
        file.close();
    }else{
        cout << "Error, Unable to read Flippers file!" << endl;
    }
}

void Configurable::ReadAudioManager(const string& TextPath) {
    file.open(TextPath);
    if (file.is_open()){
        string Trash,PlayMusic,AudioPath;
        file >> Trash;
        file >> PlayMusic;
        file >> Trash;
        file >> AudioPath;
        if(PlayMusic=="YES"){
            pAudioManager=new AudioManager(true,AudioPath);
        }else if(PlayMusic=="NO"){
            pAudioManager=new AudioManager(false,AudioPath);
        }
        file.close();
    }else{
        cout << "Unable to read AudioManager!" << endl;
    }
}

void Configurable::ReadPopBumpers(const string& TextPath) {
    file.open(TextPath);
    if(file.is_open()){
        Vector2D center;
        float radius;
        string Trash;
        file >> PopBumpersNo;
        pPopBumpers=new PopBumper*[PopBumpersNo];

        for (int i = 0; i <PopBumpersNo; i++) {
            file >> Trash;
            file >> center.x;
            file >> center.y;
            file >> Trash;
            file >> radius;

            pPopBumpers[i]=new PopBumper(center,radius);
        }
        file.close();
    }else{
        cout << "Error, unable to read PopBumpers file!" << endl;
    }

}

void Configurable::ReadManager(const string& TextPath) {
    file.open(TextPath);
    if(file.is_open()){
        string Trash;
        int lives, score;
        file >> Trash;
        file >> lives;
        file >> Trash;
        file >> score;
        pManager=new Manager(score,lives);
        file.close();
    }else{
        cout << "Unable to read Manager!" << endl;
    };
}

void Configurable::ReadWalls(string TextPath) {

}

//Drawing every object
void Configurable::DrawBalls(Interface &interface) {
    for (int i = 0; i <BallsNo; i++) {
        pBalls[i]->draw(interface);
    }
}

void Configurable::DrawFlippers(Interface &interface) {
    for (int i = 0; i <FlippersNo; i++) {
        pFlippers[i]->draw(interface);
    }
}

void Configurable::DrawPopBumpers(Interface &interface) {
    for (int i = 0; i <PopBumpersNo; i++) {
        pPopBumpers[i]->draw(interface);
    }
}

void Configurable::DrawWalls(Interface &interface) {

}

//Collision
Vector2D Configurable::FlippersCollision(Ball &ball, float collision_time, Manager &manager) {
    Vector2D Acceleration={0,0};
    for (int i = 0; i <FlippersNo; i++) {
        Acceleration+=pFlippers[i]->collideWith(ball,collision_time,manager);
    }
    return Acceleration;
}

Vector2D Configurable::PopBumpersCollision(Ball &ball, float collision_time, Manager &manager) {
    Vector2D Acceleration={0,0};
    for (int i = 0; i <PopBumpersNo; i++) {
        Acceleration+=pPopBumpers[i]->collideWith(ball,collision_time,manager);
    }
    return Acceleration;
}

Vector2D Configurable::BallsCollision(Ball &ball, float collision_time, Manager &manager) {
    Vector2D Acceleration={0,0};
    for (int i = 0; i <BallsNo; i++) {
        //Acceleration+=pBalls[i]->BallToBallCollision(ball);
    }
    return Acceleration;
}

Vector2D Configurable::WallsCollision(Ball &ball, float collision_time, Manager &manager) {
    Vector2D Acceleration={0,0};
    for (int i = 0; i <WallsNo; i++) {
        Acceleration+=pWalls[i]->collideWith(ball,collision_time,manager);
    }
    return Acceleration;
}

//Simplifications :')
void Configurable::LoadEverything() {
    //Update the total value with the number of functions.
    Progress=0;
    Total=6;
    ReadBalls("../Configurations/Balls.txt");
    Progress++;
    ReadFlippers("../Configurations/Flippers.txt");
    Progress++;
    ReadPopBumpers("../Configurations/PopBumpers.txt");
    Progress++;
    ReadWalls("../Configurations/Walls.txt");
    Progress++;
    ReadAudioManager("../Configurations/AudioManager.txt");
    Progress++;
    ReadManager("../Configurations/Manager.txt");
    Progress++;
}

void Configurable::DrawEverything(Interface & interface) {
    DrawBalls(interface);
    DrawFlippers(interface);
    DrawPopBumpers(interface);
    DrawWalls(interface);
}

void Configurable::Collision(float collision_time) {
    for (int i = 0; i <BallsNo; i++) {
        pAcceleration[i]=FlippersCollision(*pBalls[i], collision_time,*pManager);
        pAcceleration[i]=PopBumpersCollision(*pBalls[i], collision_time,*pManager);
        pAcceleration[i]=BallsCollision(*pBalls[i],collision_time,*pManager);
        //pAcceleration[i]=WallsCollision(*pBalls[i], collision_time,*pManager);
        //Move balls.
        //pBalls[i]->move(pAcceleration[i],collision_time);
    }
}

void Configurable::FlippersMotion(bool left, bool right, float delta_time) {
    for (int i = 0; i <FlippersNo; i++) {
        pFlippers[i]->MoveFlipper(left, right, delta_time);
    }
}

void Configurable::ActivateBalls(bool space) {
    for (int i = 0; i <BallsNo ;i++) {
        if(pBalls[i]->getisMain())
            pBalls[i]->Activate(space);
    }
}
