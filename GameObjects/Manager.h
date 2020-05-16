#pragma once

#include <iostream>
#include "../Interface.h"
#include "Ball.h"
using namespace std;

class Ball;

class Manager {
private:
    int Score;
    int lives;
    int AdditionalScore=0;
    string scoreText;
    string livesText;
    double timer=ControlTimer;
public:
    Manager();
    Manager(int Score, int lives);

    void addScore(int score);
    void deductLives(int Lives);

    //Getters
    string getLives();
    string getScore();

    //Update function
    void Updategame(Interface & interface);
    void ValueUpdate(Ball & ball, bool & Islost);
    void MultiplyScore(double Factor);
    void UpdateTimer(double Time);

    //Game lost
    void EndGame(Interface & interface);
};
