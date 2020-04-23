#include "Interface.h"


Interface::Interface()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  // Remove this line if the game was too laggy
    window.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Pinball", sf::Style::Titlebar, settings);
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(FPSLimit);
}

void Interface::getControls(bool & exit, bool & left, bool & right, bool & space)
{
    sf::Event event;
    while (window.pollEvent(event));
    space = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    exit = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
    left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Interface::clear()
{
    window.clear(backgroundColor);
}

void Interface::display()
{
    window.display();
}

void Interface::drawBall(Vector2D center, float radius)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(outlineThickness);
    circle.setOutlineColor(outlineColor);
    circle.setFillColor(ballFillColor);
    circle.setPosition(center.x, center.y);
    window.draw(circle);

    //Graphics b2a w kda
    Ballsprite.setTexture(Balltexture);
    Ballsprite.setPosition(center.x-radius,center.y-radius);
    Ballsprite.setScale(0.01,0.01);
    window.draw(Ballsprite);


}

void Interface::drawFlipper(FlipperType type, Vector2D center, float length, float angle, float majorRadius, float minorRadius)
{
    float flip = type == LEFT ? 1.0f : -1.0f;

    // Draw the major circle outline
    sf::CircleShape majorCircleOutline(majorRadius);
    majorCircleOutline.setOutlineThickness(outlineThickness);
    majorCircleOutline.setOutlineColor(outlineColor);
    majorCircleOutline.setFillColor(flipperFillColor);
    majorCircleOutline.setOrigin(majorRadius, majorRadius);
    majorCircleOutline.setPosition(center.x, center.y);
    window.draw(majorCircleOutline);

    // Draw the minor circle outline000000000000000000000000000000000000
    sf::CircleShape minorCircleOutline(minorRadius);
    minorCircleOutline.setOutlineThickness(outlineThickness);
    minorCircleOutline.setOutlineColor(outlineColor);
    minorCircleOutline.setFillColor(flipperFillColor);
    minorCircleOutline.setOrigin(minorRadius - length, minorRadius);
    minorCircleOutline.setPosition(center.x, center.y);
    minorCircleOutline.rotate(angle);
    minorCircleOutline.setScale(flip, 1.0f);
    window.draw(minorCircleOutline);

    // Draw the convex shape connecting the two circles
    sf::ConvexShape convexBody(4);
    convexBody.setPoint(0, sf::Vector2f(0, -outlineThickness));
    convexBody.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    convexBody.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    convexBody.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    convexBody.setFillColor(flipperFillColor);
    convexBody.setOrigin(0, majorRadius);
    convexBody.setPosition(center.x, center.y);
    convexBody.setRotation(angle);
    convexBody.setScale(flip, 1.0f);
    window.draw(convexBody);

    // Draw the inside circle
    sf::CircleShape insideCircle(minorRadius);
    insideCircle.setFillColor(outlineColor);
    insideCircle.setOrigin(minorRadius, minorRadius);
    insideCircle.setPosition(center.x, center.y);
    window.draw(insideCircle);

    // Draw the top line
    sf::ConvexShape topLine(4);
    topLine.setPoint(0, sf::Vector2f(0, -outlineThickness));
    topLine.setPoint(1, sf::Vector2f(0, 0));
    topLine.setPoint(2, sf::Vector2f(length, majorRadius - minorRadius));
    topLine.setPoint(3, sf::Vector2f(length, majorRadius - minorRadius - outlineThickness));
    topLine.setFillColor(outlineColor);
    topLine.setOrigin(0, majorRadius);
    topLine.setPosition(center.x, center.y);
    topLine.setRotation(angle);
    topLine.setScale(flip, 1.0f);
    window.draw(topLine);

    // Draw the bottom line
    sf::ConvexShape bottomLine(4);
    bottomLine.setPoint(0, sf::Vector2f(0, 2 * majorRadius));
    bottomLine.setPoint(1, sf::Vector2f(0, 2 * majorRadius + outlineThickness));
    bottomLine.setPoint(2, sf::Vector2f(length, majorRadius + minorRadius + outlineThickness));
    bottomLine.setPoint(3, sf::Vector2f(length, majorRadius + minorRadius));
    bottomLine.setFillColor(outlineColor);
    bottomLine.setOrigin(0, majorRadius);
    bottomLine.setPosition(center.x, center.y);
    bottomLine.setRotation(angle);
    bottomLine.setScale(flip, 1.0f);
    window.draw(bottomLine);
}

void Interface::drawWall(float position, bool isVertical)
{
    if(isVertical) {
        sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f(position, 0), outlineColor),
                        sf::Vertex(sf::Vector2f(position, GAME_HEIGHT), outlineColor)
                };
        window.draw(line, 2, sf::Lines);
    }else{
        sf::Vertex line[] =
                {
                        sf::Vertex(sf::Vector2f(0, position), outlineColor),
                        sf::Vertex(sf::Vector2f(GAME_WIDTH, position), outlineColor)
                };
        window.draw(line, 2, sf::Lines);
    }
}

void Interface::drawNewWall(sf::Sprite sprite) {
    window.draw(sprite);
}

void Interface::drawBumper(Vector2D center, float radius, BumperType type) {
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(1.5*outlineThickness);
    circle.setOutlineColor(sf::Color::Magenta);

    circle.setPosition(center.x, center.y);

    switch (type)
    {
        case (BumperType::POP):{
            circle.setFillColor(sf::Color::Blue);
            window.draw(circle);
            Bumpersprite.setPosition(center.x - (radius / 2) - 15, center.y - (radius / 2) - 15);
            Bumpersprite.setScale(2, 2);
            window.draw(Bumpersprite);
            break;
        }case(BumperType::THRUST):{
            circle.setFillColor(sf::Color::Transparent);
            window.draw(circle);
            Thurstsprite.setPosition(center.x-radius, center.y-radius);
            Thurstsprite.setScale(0.015, 0.015);
            window.draw(Thurstsprite);
            break;
        }case(BumperType::VIBRANIUM):{
            //drawing 2nd circle
            circle.setFillColor(sf::Color(8,105,114,255));
            window.draw(circle);
            sf::CircleShape circle1(1.5*radius);
            circle1.setOrigin(1.5*radius,1.5* radius);

            circle1.setFillColor(sf::Color::Transparent);
            circle1.setPosition(center.x, center.y);
            window.draw(circle1);
            //drawing texture for 1st circle

            Vibraniumsprite.setPosition(center.x-radius-18, center.y-radius-12);
            Vibraniumsprite.setScale(0.3, 0.3);
            window.draw(Vibraniumsprite);
            break;
        }case(BumperType::SCOREM): {
            circle.setFillColor(sf::Color(244,250,156,255));
            window.draw(circle);
            ScoreMsprite.setPosition(center.x-radius, center.y-radius);
            ScoreMsprite.setScale(0.2, 0.2);
            window.draw(ScoreMsprite);
            break;
        }
    }

}

void Interface::drawFPS() {
    text.setString(FPS);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);
    text.setPosition(0,0);
    window.draw(text);
}

void Interface::setFPS(string fps) {
    FPS=fps;
}

void Interface::drawText(string Text, int FontSize, sf::Color color, Vector2D position) {

    text.setFont(font);
    text.setString(Text);
    sf::FloatRect bounds=text.getLocalBounds();
    text.setCharacterSize(FontSize);
    text.setFillColor(color);
    text.setPosition(position.x-bounds.width/2,position.y);
    window.draw(text);
}

void Interface::LoadGraphics() {
    //Load Fonts
    if(!font.loadFromFile("../Assets/Fonts/BebasNeue-Regular.ttf")){
        cout<< "Can't load font! "<< endl;
    }else{
        FPSText.setFont(font);
    }

    //Loading Ball sprite
    if (!Balltexture.loadFromFile("../Assets/Sprites/pokeball.png")) {
        // error...
        cout << "Error loading pokeball!" << endl;
    }else{
        Ballsprite.setTexture(Balltexture);
    }
//
//if(GateTexture.loadFromFile("")) {
//    cout << "Error loading GateTexture";
//}
//    else
//    {
//        Gate.setTexture(GateTexture);//Make object for this to work
//    }
//}

    //Loading Bumper sprite
    if(!Bumpertexture.loadFromFile("../Assets/Sprites/PokeBumper.png")){
        cout << "Error loading Bumper sprite!" <<  endl;
    }else{
        Bumpersprite.setTexture(Bumpertexture);
    }

    //background sprite
    if(!backgroundTexture.loadFromFile("../Assets/background.png")){
        cout << "Error loading Bumper sprite!" <<  endl;
    }else{
        backgroundSprite.setTexture(backgroundTexture);
    }

    //Portal Sprite
    if(!PortalTexture.loadFromFile("../Assets/Sprites/Portal.png")){
        cout<< "Can't load Portal sprite! "<< endl;
    }else{
        PortalSprite.setTexture(PortalTexture);
    }

    //SpeedBooster
    if(!SpeedBoosterTexture.loadFromFile("../Assets/Sprites/SpeedBooster.png")){
        cout<< "Can't load SpeedBooster sprite! "<< endl;
    }else{
        SpeedBoosterSprite.setTexture(SpeedBoosterTexture);
    }

    //Vibranium
    if(!Vibraniumtexture.loadFromFile("../Assets/Sprites/Vibranium.png")){
        cout<< "Can't load Vibranium sprite! "<< endl;
    }else{
        Vibraniumsprite.setTexture(Vibraniumtexture);
    }

    //Thrust
    if(!Thursttexture.loadFromFile("../Assets/Sprites/Thurst.png")){
        cout<< "Can't load ThrustBumper sprite! "<< endl;
    }else{
        Thurstsprite.setTexture(Thursttexture);
    }

    //Thrust
    if(!ScoreMtexture.loadFromFile("../Assets/Sprites/ScoreMultiplier.png")){
        cout<< "Can't load ScoreMultiplier sprite! "<< endl;
    }else{
        ScoreMsprite.setTexture(ScoreMtexture);
    }

}

//Draw external frame
void Interface::loadExternalFrame(bool isVertical,float Position)
{
        if (isVertical) {
            sf::RectangleShape externalFrame(sf::Vector2f(Position, GAME_HEIGHT));
            externalFrame.setFillColor(sf::Color::Magenta);
            if (Position < 0) {
                externalFrame.setPosition(GAME_WIDTH, 0.0f);
            }
//          externalFrame.setTexture(&texture);
            window.draw(externalFrame);
        } else {
            sf::RectangleShape externalFrame(sf::Vector2f(GAME_WIDTH, Position));
            externalFrame.setFillColor(sf::Color::Magenta);
//          externalFrame.setTexture(&texture);
            window.draw(externalFrame);
        }
}

void Interface::loadInternalFrame(bool is45,bool isLeft,float Diameter, float LineXCoordinate,
        float LineYCoordinate, float InclinationAngle, float setPositionX,float setPositionYRation)
{
//    sf::Texture texture;
//    texture.loadFromFile("Frame.png");
if(is45)
{
    sf::RectangleShape line(sf::Vector2f(LineXCoordinate, LineYCoordinate));
    line.rotate(InclinationAngle);
    line.setPosition(setPositionX, GAME_HEIGHT * setPositionYRation);
    line.setFillColor(sf::Color::Magenta);
//    line.setTexture(&texture);

    if(!isLeft)
    {
        line.rotate(2*InclinationAngle);
        line.setPosition(GAME_WIDTH-36.f, GAME_HEIGHT * setPositionYRation);
        line.setFillColor(sf::Color::Magenta);
    }
    window.draw(line);
}
else
    {
        sf::RectangleShape internalFrame(sf::Vector2f(10.f, GAME_HEIGHT));
        internalFrame.setFillColor(sf::Color::Magenta);
        internalFrame.setPosition(GAME_WIDTH-20-Diameter,400.0f);
//        internalFrame.setTexture(&texture);
//        window.draw(internalFrame);
    window.draw(internalFrame);
}

}

void Interface::drawLeftKicker(float x1,float y1,float x2,float y2,float x3,float y3) {
    sf::ConvexShape SpeedBoaster;
    SpeedBoaster.setPointCount(3);
    SpeedBoaster.setPoint(0,sf::Vector2f (25,735.0)); //Replace x,y variables by these numbers when loading from the file
    SpeedBoaster.setPoint(1,sf::Vector2f (130,850));
    SpeedBoaster.setPoint(2,sf::Vector2f (25,600));
    SpeedBoaster.setFillColor(sf::Color::Cyan);
    window.draw(SpeedBoaster);
}

void Interface::drawRightKicker(float x1,float y1,float x2,float y2,float x3,float y3)
{//Replace x,y variables by these numbers when loading from the file
    sf::ConvexShape SpeedBoaster;//غير اسم البتاعة ديه ل Kicker
    SpeedBoaster.setPointCount(3);
    SpeedBoaster.setPoint(0,sf::Vector2f (GAME_WIDTH-30-25,735.0));
    SpeedBoaster.setPoint(1,sf::Vector2f (GAME_WIDTH-30-130,850));
    SpeedBoaster.setPoint(2,sf::Vector2f (GAME_WIDTH-30-25,600));
    SpeedBoaster.setFillColor(sf::Color::Cyan);
    window.draw(SpeedBoaster);
}

void Interface::drawBackground()
{
    window.draw(backgroundSprite);
}

void Interface::drawPortals(Vector2D Pos1, Vector2D Pos2,double radius) {
    sf::CircleShape circle1(radius),circle2(radius);
    circle1.setOrigin(0, 0);
    circle1.setOutlineThickness(outlineThickness);
    circle1.setOutlineColor(sf::Color::Magenta);

    circle2.setOrigin(0,0);
    circle2.setOutlineThickness(outlineThickness);
    circle2.setOutlineColor(sf::Color::Magenta);

    circle1.setPosition(Pos1.x,Pos1.y);
    circle2.setPosition(Pos2.x,Pos2.y);
    window.draw(circle2);
    window.draw(circle1);

    //Sprite
    PortalSprite.setPosition(Pos1.x,Pos1.y);
    PortalSprite.setScale(0.1,0.1);
    window.draw(PortalSprite);

    PortalSprite.setPosition(Pos2.x,Pos2.y);
    PortalSprite.setScale(0.1,0.1);
    window.draw(PortalSprite);
}

void Interface::drawGate(float length,float width,float setPositionX,float setPositionY) {
    sf::RectangleShape Gate(sf::Vector2f (length,width));
    Gate.setFillColor(sf::Color::Red);
    Gate.setPosition(setPositionX,setPositionY);
    window.draw(Gate);
}
void Interface::drawMagnet(Vector2D Position, double magnetRadius, double radius, sf::Sprite * sprite) {
    sf::CircleShape magnet(magnetRadius),object(radius);
    magnet.setOrigin(magnetRadius,magnetRadius);
    magnet.setOutlineThickness(outlineThickness);
    magnet.setOutlineColor(sf::Color::Black);
    magnet.setFillColor(sf::Color(7,26,82,80));

    object.setOrigin(radius,radius);
    object.setOutlineThickness(outlineThickness);
    object.setOutlineColor(sf::Color::Black);
    object.setFillColor(sf::Color::Transparent);

    magnet.setPosition(Position.x,Position.y);
    object.setPosition(Position.x,Position.y);
    window.draw(magnet);
    window.draw(object);



    //Sprite
    sprite->setPosition(Position.x-radius,Position.y-radius);
    sprite->setScale(0.07,0.07);
    window.draw(*sprite);
}

void Interface::drawCollectable(float radius, string L, Vector2D Center) {
    sf::CircleShape Collectable(radius);
    Collectable.setFillColor(sf::Color::Transparent);
    drawText(L, 30,sf::Color(100,250,50), {Center.x+radius,Center.y-radius/3 });
    Collectable.setPosition(Center.x,Center.y);
    Collectable.setOutlineThickness(2);
    window.draw(Collectable);
}

void Interface::drawSpeedBooster(float radius,Vector2D Center){
    sf::CircleShape SpeedBooster(radius);
    SpeedBooster.setFillColor(sf::Color::Transparent);
    SpeedBooster.setPosition(Center.x,Center.y);
    SpeedBooster.setOutlineThickness(0.2);
    SpeedBooster.setOutlineColor(sf::Color::Yellow);
    window.draw(SpeedBooster);

    SpeedBoosterSprite.setPosition(Center.x,Center.y);
    SpeedBoosterSprite.setScale(0.07,0.07);
    window.draw(SpeedBoosterSprite);
}

void Interface::drawSwitch(Vector2D pos) {
    sf::RectangleShape line(sf::Vector2f(90, 20));
    line.setOrigin(0,0);
    line.setPosition(pos.x, pos.y);
    line.setFillColor(sf::Color::Cyan);
    line.setRotation(45);
    window.draw(line);
}