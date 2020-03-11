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
    interface.drawText("Assets/Fonts/BebasNeue-Regular.ttf",scoreText,42,sf::Color::Blue,{GAME_WIDTH/2,0});
    //Update Lives
    interface.drawText("Assets/Fonts/BebasNeue-Regular.ttf",livesText,42,sf::Color::Green,{GAME_WIDTH-140,0});
}

void Manager::ValueUpdate(Ball & ball, bool & IsLost) {
    //Makes sure ball doesn't glitch outside.
    //Detects lives deduction.
    if(ball.getCenter().x<0| ball.getCenter().y<0 |ball.getCenter().x>GAME_WIDTH ) {
        if(ball.getCenter().x<0)
            ball.setCenter({0 + ball.getRadius(), ball.getCenter().y});

        if(ball.getCenter().y<0)
            ball.setCenter({ball.getCenter().x, 0+ball.getRadius()});

        if(ball.getCenter().x>GAME_WIDTH)
            ball.setCenter({GAME_WIDTH-ball.getRadius(), ball.getCenter().y});

    }
    if(ball.getCenter().y>GAME_HEIGHT){
<<<<<<< HEAD
=======
        ball.deActivate();
>>>>>>> master
        ball.setCenter(INITIAL_CENTER);
        ball.setVelocity(INITIAL_VELOCITY);
        if (lives>0) {
            lives--;
        }else{
            IsLost=true;
        }
    }
}

void Manager::EndGame(Interface & interface) {
    // You lost text
    interface.drawText("Assets/Fonts/BebasNeue-Regular.ttf","YOU LOST", 72, sf::Color::Red,{GAME_WIDTH/2,GAME_HEIGHT/2-200});
    //Final score text
    interface.drawText("Assets/Fonts/BebasNeue-Regular.ttf",scoreText, 72, sf::Color::Cyan,{GAME_WIDTH/2,GAME_HEIGHT/2});
}
