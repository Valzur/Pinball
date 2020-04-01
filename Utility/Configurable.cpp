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
    if(file.is_open()){
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
            file.close();
        }
    }else{
        cout << "Error, Unable to read Flippers file!" << endl;
    }
}

void Configurable::DrawEverything(Interface & interface) {
    DrawBalls(interface);
    DrawFlippers(interface);
    DrawPopBumpers(interface);
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
    ReadPopBumpers("../Configurations/PopBumpers.txt");
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
    PopBumpersCollision(ball, collision_time,*pManager);
    BallsCollision(ball,collision_time,*pManager);
    WallsCollision(ball, collision_time,*pManager);
}

void Configurable::FlippersCollision(Ball &ball, float collision_time, Manager &manager) {
    for (int i = 0; i <FlippersNo; i++) {
        Acceleration+=pFlippers[i]->collideWith(ball,collision_time,manager);
    }
}

void Configurable::PopBumpersCollision(Ball &ball, float collision_time, Manager &manager) {
    for (int i = 0; i <PopBumpersNo; i++) {
        Acceleration+=pPopBumpers[i]->collideWith(ball,collision_time,manager);
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

void Configurable::ReadPopBumpers(string TextPath) {
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
    }else{
        cout << "Error, unable to read PopBumpers file!" << endl;
    }

}

void Configurable::ReadWalls(string TextPath) {

}

void Configurable::ReadManager(string TextPath) {

}

void Configurable::ReadAudioManager(string TextPath) {

}

void Configurable::DrawWalls(Interface &interface) {

}

void Configurable::DrawPopBumpers(Interface &interface) {
    for (int i = 0; i <PopBumpersNo; i++) {
        pPopBumpers[i]->draw(interface);
    }
}
