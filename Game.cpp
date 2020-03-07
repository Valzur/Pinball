#include <iostream>
#include "Game.h"

#define GRAVITY 400.0f

Game::Game(): leftFlipper(LEFT, Vector2D { GAME_WIDTH / 2.0f - (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f),GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, 30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
              rightFlipper(RIGHT, Vector2D { GAME_WIDTH / 2.0f + (FLIPPER_LENGTH + FLIPPERS_DISTANCE / 2.0f), GAME_HEIGHT - 50.0f}, FLIPPER_LENGTH, -30.0f, FLIPPER_MAJOR_RADIUS, FLIPPER_MINOR_RADIUS),
              bumper1({GAME_WIDTH/3,GAME_HEIGHT/2},70),bumper2({2*GAME_WIDTH/3,GAME_HEIGHT/2},70),
              leftWall(1,true), rightWall(GAME_WIDTH, true),upperWall(1, false) // This line should be removed,
{
    last_frame = high_resolution_clock::now();
    exit = left = right = false;
}

void Game::readInterfaceInput()
{
    interface.getControls(exit, left, right);
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


    Vector2D resultant_acceleration = {0, GRAVITY};  // Starting with gravity as the first acceleration contributer
    resultant_acceleration += bumper1.collidewith(ball,delta_time,manager);
    resultant_acceleration += bumper2.collidewith(ball,delta_time,manager);
    resultant_acceleration += leftWall.collideWith(ball, delta_time);
    resultant_acceleration += rightWall.collideWith(ball, delta_time);
    resultant_acceleration += upperWall.collideWith(ball,delta_time);
    ball.move(resultant_acceleration, delta_time);
    manager.ValueUpdate(ball, Lost);
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

        ball.draw(interface);
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


