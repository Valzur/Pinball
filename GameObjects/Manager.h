#pragma once

#include <iostream>
#include "../Interface.h"
#include "Ball.h"
using namespace std;

class Manager {
private:
    int Score;
    int lives;
    string scoreText;
    string livesText;
public:
    Manager();

    void addScore(int score);
    void deductLives(int Lives);

    //Getters
    int getLives();

    //Update function
    void Updategame(Interface & interface);
    void ValueUpdate(Ball & ball, bool & Islost);

    //Game lost
    void EndGame(Interface & interface);
};
