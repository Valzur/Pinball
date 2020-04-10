#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Defs.h"
#include <iostream>

using namespace std;

// Represents the game interface
// This class is the ONLY one that interacts with the user
// This class is also the ONLY one aware of the graphics library being used
// That is, if the graphics library was to be changes, this class is the only thing to be changed
class Interface
{
private:
    string FPS;
    //Fonts and Texts
    sf::Font font;
    sf::Text text;
    sf::Text FPSText;

    sf::RenderWindow window;  // Represents the game window
    const sf::Color  // Colors used for drawing (can change the whole theme of the game)
        backgroundColor = sf::Color::White,
        outlineColor = sf::Color::Black,
        ballFillColor = sf::Color::White,
        flipperFillColor = sf::Color::White;
    const float outlineThickness = -2.0f;  // Negative sign means inwards

    //Sprites and textures
    sf::Texture Balltexture;
    sf::Sprite Ballsprite;

    sf::Texture Bumpertexture;
    sf::Sprite Bumpersprite;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Texture PortalTexture;
    sf::Sprite PortalSprite;

public:
    Interface();  // Constructor
    void getControls(bool & exit, bool & left, bool & right, bool & space);  // Detects the buttons pressed
    void setFPS(string fps);

    void clear();  // Clears the frame (first step in rendering a new frame)
    void display();  // Displays the frame (last step in rendering a new frame)

    void drawBall(Vector2D center, float radius);  // Draws a ball
    void drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minor_radius);  // Draws a flipper
    void drawWall(float position,bool isVertical);  // Draws a vertical wall
    void drawNewWall(sf::Sprite sprite);
    void drawBumper(Vector2D center, float radius);
    void drawPortals(Vector2D Pos1, Vector2D Pos2,double radius);

    //Utility
    void drawFPS();
    void drawText(string Text, int FontSize, sf::Color color, Vector2D position);

    void LoadGraphics();
    void drawBackground();


    void loadExternalFrame(bool isVertical, float Position);


    void loadInternalFrame(bool is45,bool isLeft,float Diameter, float LineXCoordinate, float LineYCoordinate, float InclinationAngle, float setPositionX,float setPositionYRation);
    void drawSpeedBoasterLeft(float x1,float y1,float x2,float y2,float x3,float y3);
    void drawSpeedBoasterRight(float x1,float y1,float x2,float y2,float x3,float y3);

};
