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
        backgroundColor = sf::Color(240, 240, 240),
        outlineColor = sf::Color(54, 79, 107),
        ballFillColor = sf::Color::White,
        flipperFillColor = sf::Color::White,
        textColor = sf::Color(252, 81, 133),
        RadiantColor = sf::Color(67, 221, 230);
    const double outlineThickness = -2.0f;  // Negative sign means inwards

    //Sprites and textures
    sf::Texture Balltexture;
    sf::Sprite Ballsprite;

    sf::Texture Bumpertexture,Thursttexture,Vibraniumtexture,ScoreMtexture;
    sf::Sprite Bumpersprite,Thurstsprite,Vibraniumsprite,ScoreMsprite;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Texture PortalTexture;
    sf::Sprite PortalSprite;

    sf::Texture SpeedBoosterTexture;
    sf::Sprite SpeedBoosterSprite;

    sf::Texture RampTexture;
    sf::Sprite RampSprite;
public:
    Interface();  // Constructor
    void getControls(bool & exit, bool & left, bool & right, bool & space);  // Detects the buttons pressed
    void setFPS(string fps);

    void clear();  // Clears the frame (first step in rendering a new frame)
    void display();  // Displays the frame (last step in rendering a new frame)

    void drawBall(Vector2D center, double radius);  // Draws a ball
    void drawFlipper(FlipperType type, Vector2D center, double length, double angle, double majorRadius, double minor_radius);  // Draws a flipper
    void drawWall(double position,bool isVertical);  // Draws a vertical Wall
    void drawNewWall(sf::Sprite sprite);
    void drawBumper(Vector2D center, double radius, BumperType type,bool Hit=false);
    void drawPortals(Vector2D Pos1, Vector2D Pos2,double radius);
    void drawMagnet(Vector2D Position, double magnetRadius,double radius,sf::Sprite * sprite);
    void drawSwitch(Vector2D pos);
    void drawCollectable(double radius,string L,Vector2D Center,bool Used);
    void drawSpeedBooster(double radius,Vector2D Center);
    void drawGate(double length,double width,Vector2D Center,bool AllowUp=false);
    void drawLane(double Length, Vector2D Center, double Width);
    void drawRamp(Vector2D Center);
    void drawScoreMultiplier(Vector2D Center, double Radius);
    void drawBullseye(Vector2D Center,double Length, double Width, bool isVertical);

    //Utility
    void drawFPS();
    void drawText(string Text, int FontSize, Vector2D position);

    void LoadGraphics();
    void drawBackground();
    void drawUIBackground();

    void drawWall(bool isVertical, double Position);

    void drawRamp   (bool is45, bool isLeft, double Diameter, double LineXCoordinate, double LineYCoordinate, double InclinationAngle, double setPositionX, double setPositionYRation);
    void drawLeftKicker(double x1,double y1,double x2,double y2,double x3,double y3);
    void drawRightKicker(double x1,double y1,double x2,double y2,double x3,double y3);

    sf::RenderWindow& GetWindow();
};
