#include "Configurable.h"

void Configurable::ReadBalls(string TextPath) {
    Vector2D velocity, center;
    string IsMain, Trash;
    file.open(TextPath);
    if (file.is_open()) {
        file >> BallsNo;
        pBalls = new Ball *[BallsNo];

        for (int i = 0; i < BallsNo; ++i) {
            //Center first
            file >> Trash;
            file >> center.x;
            file >> center.y;
            //Velocity second
            file >> Trash;
            file >> velocity.x;
            file >> velocity.y;
            //If main last
            file >> Trash;
            file >> IsMain;
            if (IsMain == "YES") {
                pBalls[i] = new Ball(center, velocity, true);
            } else if (IsMain == "NO") {
                pBalls[i] = new Ball(center, velocity, false);
            }
        }
        file.close();
    }else{
        cout << "Error, unable to read Balls file!" << endl;
    }
}

void Configurable::DrawBalls(Interface &interface) {
    for (int i = 0; i <BallsNo; i++) {
        pBalls[i]->draw(interface);
    }
}

void Configurable::ReadFlippers(string TextPath) {
    file.open(TextPath);
    file >> FlippersNo;
    pFlippers=new Flipper*[FlippersNo];

    for (int i = 0; i <FlippersNo; i++) {
        Vector2D Center;
        string Flippertype, Trash;
        float length, angle, MajorRadius, MinorRadius;
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
        //Phew, i hope i get no errors after all of this.
        if(Flippertype=="RIGHT") {
            pFlippers[i]=new Flipper(FlipperType::RIGHT,Center,length,angle,MajorRadius,MinorRadius);
        } else if (Flippertype=="LEFT"){
            pFlippers[i]=new Flipper(FlipperType::LEFT,Center,length,angle,MajorRadius,MinorRadius);
        }
    }
}

void Configurable::DrawEverything(Interface & interface) {
    DrawBalls(interface);
    DrawFlippers(interface);
    DrawBumpers(interface);
    DrawWalls(interface);
}

void Configurable::DrawFlippers(Interface &interface) {
    for (int i = 0; i <FlippersNo; i++) {
        pFlippers[i]->draw(interface);
    }
}

void Configurable::LoadEverything() {
    //Update the total value with the number of functions.
    Progress=0;
    Total=6;
    ReadBalls("../Configurations/Balls.txt");
    Progress++;
    ReadFlippers("../Configurations/Flippers.txt");
    Progress++;
    ReadBumpers("../Configurations/Bumpers.txt");
    Progress++;
    ReadWalls("../Configurations/Walls.txt");
    Progress++;
    ReadAudioManager("../Configurations/AudioManager.txt");
    Progress++;
    ReadManager("../Configurations/Manager.txt");
    Progress++;
}

void Configurable::Collision(Ball &ball, float collision_time) {
    FlippersCollision(ball, collision_time,*pManager);
    BumpersCollision(ball, collision_time,*pManager);
    BallsCollision(ball,collision_time,*pManager);
    WallsCollision(ball, collision_time,*pManager);
}

void Configurable::FlippersCollision(Ball &ball, float collision_time, Manager &manager) {
    for (int i = 0; i <FlippersNo; i++) {
        Acceleration+=pFlippers[i]->collideWith(ball,collision_time,manager);
    }
}

void Configurable::BumpersCollision(Ball &ball, float collision_time, Manager &manager) {
    for (int i = 0; i <BumpersNo; i++) {
        Acceleration+=pBumpers[i]->collideWith(ball,collision_time,manager);
    }
}

void Configurable::BallsCollision(Ball &ball, float collision_time, Manager &manager) {
    for (int i = 0; i <BallsNo; i++) {
        Acceleration+=pBalls[i]->BallToBallCollision(ball);
    }
}

void Configurable::WallsCollision(Ball &ball, float collision_time, Manager &manager) {
    for (int i = 0; i <WallsNo; i++) {
        Acceleration+=pWalls[i]->collideWith(ball,collision_time,manager);
    }
}

void Configurable::ReadBumpers(string TextPath) {

}

void Configurable::ReadWalls(string TextPath) {

}

void Configurable::ReadManager(string TextPath) {

}

void Configurable::ReadAudioManager(string TextPath) {

}

void Configurable::DrawWalls(Interface &interface) {

}

void Configurable::DrawBumpers(Interface &interface) {

}
