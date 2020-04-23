#include "Manager.h"

Manager::Manager() {
    Score=0;
    lives=3;
}

void Manager::addScore(int score) {
    Score+=score;
}

void Manager::deductLives(int Lives) {
    lives-=Lives;
}

int Manager::getLives() {
    return lives;
}

void Manager::Updategame(Interface & interface) {
    //Generate Text values
    scoreText="Score: " + to_string(Score);
    livesText="Lives: " + to_string(lives);

    //Update Score
    interface.drawText(scoreText,42,sf::Color::Blue,{GAME_WIDTH/2,0});
    //Update Lives
    interface.drawText(livesText,42,sf::Color::Green,{GAME_WIDTH-140,0});
}

void Manager::ValueUpdate(Ball & ball, bool & IsLost) {
    //Makes sure ball doesn't glitch outside.
    //Detects lives deduction.
    if(ball.getCenter().x<ball.getRadius()| ball.getCenter().y<ball.getRadius() |ball.getCenter().x>GAME_WIDTH-ball.getRadius()) {
        if(ball.getCenter().y<ball.getRadius())
            ball.setCenter({ball.getCenter().x, ball.getRadius()-1});

        if(ball.getCenter().x<ball.getRadius()){
            ball.setCenter({ball.getRadius()-1,ball.getCenter().y});
        }else if(ball.getCenter().x>GAME_WIDTH-ball.getRadius()){
            ball.setCenter({GAME_WIDTH-ball.getRadius()+1,ball.getCenter().y});
        }
    }
    if(ball.getCenter().y>GAME_HEIGHT){
        ball.Reset();
        if (lives>0) {
            lives--;
        }else{
            IsLost=true;
        }
    }
}

void Manager::EndGame(Interface & interface) {
    // You lost text
    interface.drawText("YOU LOST", 72, sf::Color::Red,{GAME_WIDTH/2,GAME_HEIGHT/2-200});
    //Final score text
    interface.drawText(scoreText, 72, sf::Color::Cyan,{GAME_WIDTH/2,GAME_HEIGHT/2});
}

Manager::Manager(int Score, int lives) {
    this->Score=Score;
    this->lives=lives;
}

int Manager::getScore() {
    return Score;
}
