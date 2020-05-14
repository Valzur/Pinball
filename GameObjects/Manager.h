#pragma once

#include <iostream>
#include "../Interface.h"
#include "Ball.h"
using namespace std;

class Ball;

class Manager {
private:
    int Score=0;
    int lives;
    string scoreText;
    string livesText;
public:
    Manager();
    Manager(int Score, int lives);

    void addScore(int score);
    void deductLives(int Lives);

    //Getters
    int getLives();
    int getScore();

    //Update function
    void Updategame(Interface & interface);
    void ValueUpdate(Ball & ball, bool & Islost);
    void MultiplyScore(double Factor);

    //Game lost
    void EndGame(Interface & interface);
};
