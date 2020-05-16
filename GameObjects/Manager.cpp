#include "Manager.h"

Manager::Manager() {
    Score=0;
    lives=3;
}

void Manager::addScore(int score) {
    if(timer<=0){
        AdditionalScore+=score;
        timer = ControlTimer;
    }
}

void Manager::deductLives(int Lives) {
    lives-=Lives;
}

string Manager::getLives() {
    return "Lives: " + to_string(lives);
}

void Manager::Updategame(Interface & interface) {
    Score = Score + AdditionalScore;
    AdditionalScore = 0;
    //Generate Text values
    scoreText="Score: " + to_string(Score);
    livesText="Lives: " + to_string(lives);

    //Update Score
    interface.drawText(scoreText,42,{GAME_WIDTH+2,0});
    //Update Lives
    interface.drawText(livesText,42,{GAME_WIDTH+2,50});
}

void Manager::ValueUpdate(Ball & ball, bool & IsLost) {
    //Detects lives deduction.
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
    sf::RectangleShape Background(sf::Vector2f(GAME_WIDTH,GAME_HEIGHT)),
    Box(sf::Vector2f(600,300));

    //Aesthetics
    Background.setFillColor(sf::Color(240,240,240));
    Box.setFillColor(sf::Color(54, 79, 107));

    //Positioning
    Background.setOrigin(GAME_WIDTH/2.0,GAME_HEIGHT/2.0);
    Box.setOrigin(300,150);
    Background.setPosition(GAME_WIDTH/2.0,GAME_HEIGHT/2.0);
    Box.setPosition(WINDOW_WIDTH/2.0,GAME_HEIGHT/2.0);
    //Drawing
    interface.GetWindow().draw(Background);
    interface.GetWindow().draw(Box);
    // You lost text
    interface.drawText("YOU LOST", 72, {WINDOW_WIDTH/2.0-100,GAME_HEIGHT/2.0-100});
    //Final score text
    interface.drawText(scoreText, 72, {WINDOW_WIDTH/2.0-100,GAME_HEIGHT/2.0});
}

Manager::Manager(int Score, int lives) {
    this->Score=Score;
    this->lives=lives;
}

string Manager::getScore() {
    return "Score: " + to_string(Score);
}

void Manager::MultiplyScore(double Factor) {
    Score*=Factor;
}

void Manager::UpdateTimer(double Time) {
    if(timer>0)
        timer-=Time;
}
