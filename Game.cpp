#include <iostream>
#include "Game.h"

#define GRAVITY 400.0f

Game::Game(): leftFlipper(LEFT, Vector2D { GAME_WIDTH / 2.0f - (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f),GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, 30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
              rightFlipper(RIGHT, Vector2D { GAME_WIDTH / 2.0f + (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, -30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
              bumper1({GAME_WIDTH/3,GAME_HEIGHT/2},70,Pop),bumper2({2*GAME_WIDTH/3,GAME_HEIGHT/2},70,Pop),
              audioManager(true,"Audio/NEFFEX.flac"),captive1({200,300},INITIAL_VELOCITY, false),captive2({500,300},INITIAL_VELOCITY, false),
              leftWall(1,true), rightWall(GAME_WIDTH, true),upperWall(1, false) // This line should be removed,
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
    // Measuring time elapsed in-between frames
    high_resolution_clock::time_point this_frame = high_resolution_clock::now();
    duration<float> time_span = duration_cast<duration<float>>(this_frame - last_frame);
    last_frame = this_frame;
    float delta_time = time_span.count();  // Delta time in seconds

    switch(left){
        case 1:
            leftFlipper.RotateFlipper(-FLIPPERS_ANGLE_EXTENDED,delta_time);
            break;
        case 0:
            leftFlipper.RotateFlipper(-FLIPPERS_ANGLE_NORMAL,delta_time);
            break;
    }
    switch(right){
        case 1:
            rightFlipper.RotateFlipper(FLIPPERS_ANGLE_EXTENDED,delta_time);
            break;
        case 0:
            rightFlipper.RotateFlipper(FLIPPERS_ANGLE_NORMAL,delta_time);
            break;
    }

    //Update fps
    interface.setFPS("FPS: " + to_string(1.0/delta_time));

    if(space)
        ball.Activate();

    //Test
    rightFlipper.collideWith(ball,delta_time);
    leftFlipper.collideWith(ball,delta_time);


    //Ball Collision
    DoBallCollision(ball,delta_time,0);
    DoBallCollision(captive1,delta_time,1);
    DoBallCollision(captive2,delta_time,2);
}

void Game::updateInterfaceOutput()
{
    interface.clear();
    if(!Lost) {

        leftFlipper.draw(interface);
        rightFlipper.draw(interface);

        //FPS UPDATE
        interface.drawFPS();

        //Game state
        manager.Updategame(interface);

        // The following two lines be replaced with a loop over collidable obstacles
        leftWall.draw(interface);
        rightWall.draw(interface);
        upperWall.draw(interface);

        //Actual boundaries
        interface.drawBumper(bumper1.GetPosition(), bumper1.GetRadius());
        interface.drawBumper(bumper2.GetPosition(), bumper2.GetRadius());

        //End Here
        //Draw all balls
        ball.draw(interface);
        captive1.draw(interface);
        captive2.draw(interface);
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

void Game::DoBallCollision(Ball & inball,float delta_time,int isMain) {
    Vector2D resultant_acceleration = {0, GRAVITY};  // Starting with gravity as the first acceleration contributer

    //Bumpers
    resultant_acceleration += bumper1.collidewith(inball,delta_time,manager);
    resultant_acceleration += bumper2.collidewith(inball,delta_time,manager);
    //Other balls
    switch (isMain){
        case 0:
            //Main ball
            resultant_acceleration += inball.BallToBallCollision(captive1);
            resultant_acceleration += inball.BallToBallCollision(captive2);
            break;
        case 1:
            //First Captive
            resultant_acceleration += inball.BallToBallCollision(captive2);
            resultant_acceleration += inball.BallToBallCollision(ball);
            break;
        case 2:
            //Second Captive
            resultant_acceleration += inball.BallToBallCollision(ball);
            resultant_acceleration += inball.BallToBallCollision(captive1);
            break;
    }
    //Walls
    resultant_acceleration += leftWall.collideWith(inball, delta_time);
    resultant_acceleration += rightWall.collideWith(inball, delta_time);
    resultant_acceleration += upperWall.collideWith(inball,delta_time);

    //Debug
    resultant_acceleration=resultant_acceleration;
    //Motion
    inball.move(resultant_acceleration, delta_time);
    manager.ValueUpdate(inball, Lost);
}