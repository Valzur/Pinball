#include "Interface.h"


Interface::Interface()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  // Remove this line if the game was too laggy
    window.create(sf::VideoMode(WINDOW_WIDTH, GAME_HEIGHT), "Pinball", sf::Style::Titlebar, settings);
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

void Interface::drawBall(Vector2D center, double radius)
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
    Ballsprite.setOrigin(Ballsprite.getTexture()->getSize().x/2.0,Ballsprite.getTexture()->getSize().y/2.0);
    Ballsprite.setPosition(center.x,center.y);
    Ballsprite.setScale(0.01,0.01);
    window.draw(Ballsprite);


}

void Interface::drawFlipper(FlipperType type, Vector2D center, double length, double angle, double majorRadius, double minorRadius)
{
    double flip = type == LEFT ? 1.0f : -1.0f;

    // Draw the major circle outline
    sf::CircleShape majorCircleOutline(majorRadius);
    majorCircleOutline.setOutlineThickness(outlineThickness);
    majorCircleOutline.setOutlineColor(outlineColor);
    majorCircleOutline.setFillColor(flipperFillColor);
    majorCircleOutline.setOrigin(majorRadius, majorRadius);
    majorCircleOutline.setPosition(center.x, center.y);
    window.draw(majorCircleOutline);

    // Draw the minor circle outline
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

void Interface::drawWall(Vector2D Center, bool isVertical){
    if(isVertical) {
        sf::RectangleShape Wall({10,GAME_HEIGHT});

        //Origin
        Wall.setOrigin({5,GAME_HEIGHT/2.0});

        //Aesthetics
        Wall.setFillColor(outlineColor);

        //Position
        Wall.setPosition(Center);

        window.draw(Wall);
    }else{
        sf::RectangleShape Wall({GAME_WIDTH,10});

        //Origin
        Wall.setOrigin({GAME_WIDTH/2.0,5});

        //Aesthetics
        Wall.setFillColor(outlineColor);

        //Position
        Wall.setPosition(Center);

        window.draw(Wall);
    }
}


void Interface::drawBumper(Vector2D center, double radius, BumperType type,bool Hit) {
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(1.5*outlineThickness);
    circle.setOutlineColor(outlineColor);

    circle.setPosition(center.x, center.y);

    switch (type)
    {
        case (BumperType::POP):{
            if(!Hit){
                circle.setFillColor(RadiantColor);
            }else{
                circle.setFillColor(textColor);
            }

            window.draw(circle);
            Bumpersprite.setOrigin(Bumpersprite.getTexture()->getSize().x/2.0,Bumpersprite.getTexture()->getSize().y/2.0);
            Bumpersprite.setPosition(center.x , center.y);
            Bumpersprite.setScale(2, 2);
            window.draw(Bumpersprite);
            break;
        }case(BumperType::THRUST):{
            circle.setFillColor(sf::Color::Transparent);
            window.draw(circle);
            ThrustSprite.setOrigin(ThrustSprite.getTexture()->getSize().x/2.0,ThrustSprite.getTexture()->getSize().y/2.0);
            ThrustSprite.setPosition(center.x, center.y);
            ThrustSprite.setScale(0.015, 0.015);
            window.draw(ThrustSprite);
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
            Vibraniumsprite.setOrigin(Vibraniumsprite.getTexture()->getSize().x/2.0,Vibraniumsprite.getTexture()->getSize().y/2.0);
            Vibraniumsprite.setPosition(center.x, center.y);
            Vibraniumsprite.setScale(0.3, 0.3);
            window.draw(Vibraniumsprite);
            break;
        }case(BumperType::SCOREM): {
            if(Hit){
                circle.setFillColor(textColor);
            }else{
                circle.setFillColor(RadiantColor);
            }
            window.draw(circle);
            ScoreMsprite.setOrigin(ScoreMsprite.getTexture()->getSize().x/2.0,ScoreMsprite.getTexture()->getSize().y/2.0);
            ScoreMsprite.setPosition(center);
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

void Interface::drawText(string Text, int FontSize, Vector2D position) {

    text.setFont(font);
    text.setString(Text);
    sf::FloatRect bounds=text.getLocalBounds();
    text.setCharacterSize(FontSize);
    text.setFillColor(textColor);
    text.setOrigin(0,0);
    text.setPosition(position.x,position.y);
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
    if(!ThrustTexture.loadFromFile("../Assets/Sprites/Thurst.png")){
        cout<< "Can't load ThrustBumper sprite! "<< endl;
    }else{
        ThrustSprite.setTexture(ThrustTexture);
    }

    //Thrust
    if(!ScoreMtexture.loadFromFile("../Assets/Sprites/ScoreMultiplier.png")){
        cout<< "Can't load ScoreMultiplier sprite! "<< endl;
    }else{
        ScoreMsprite.setTexture(ScoreMtexture);
    }

    //Ramps
    if(!RampTexture.loadFromFile("../Assets/Sprites/Ramp.png")){
        cout<< "Can't load Ramp sprite! "<< endl;
    }else{
        RampSprite.setTexture(RampTexture);
    }

}

//Draw external frame
void Interface::drawWall(bool isVertical, double Position)
{
        if (isVertical) {
            sf::RectangleShape externalFrame(sf::Vector2f(Position, GAME_HEIGHT));
            externalFrame.setFillColor(outlineColor);
            if (Position < 0) {
                externalFrame.setPosition(GAME_WIDTH, 0.0f);
            }
            window.draw(externalFrame);
        } else {
            sf::RectangleShape externalFrame(sf::Vector2f(GAME_WIDTH, Position));
            externalFrame.setFillColor(outlineColor);

            window.draw(externalFrame);
        }
}

void Interface::drawRamp(bool is45, bool isLeft, double Diameter, Vector2D Size, double InclinationAngle, double setPositionX, double setPositionYRation){

if(is45)
{
    sf::RectangleShape line(Size);
    line.rotate(InclinationAngle);
    line.setPosition(setPositionX, GAME_HEIGHT * setPositionYRation);
    line.setFillColor(outlineColor);

    if(!isLeft)
    {
        line.rotate(2*InclinationAngle);
        line.setPosition(GAME_WIDTH-36.f, GAME_HEIGHT * setPositionYRation);
        line.setFillColor(outlineColor);
    }
    window.draw(line);
}
else
    {
        sf::RectangleShape internalFrame(sf::Vector2f(10.f, GAME_HEIGHT));
        internalFrame.setFillColor(outlineColor);
        internalFrame.setPosition(GAME_WIDTH-20-Diameter,400.0f);
    window.draw(internalFrame);
}

}

void Interface::drawLeftKicker(double x1,double y1,double x2,double y2,double x3,double y3) {
    sf::ConvexShape SpeedBoaster;
    SpeedBoaster.setPointCount(3);
    SpeedBoaster.setPoint(0,sf::Vector2f (25,735.0)); //Replace x,y variables by these numbers when loading from the file
    SpeedBoaster.setPoint(1,sf::Vector2f (130,850));
    SpeedBoaster.setPoint(2,sf::Vector2f (25,600));
    SpeedBoaster.setFillColor(sf::Color::Cyan);
    window.draw(SpeedBoaster);
}

void Interface::drawRightKicker(double x1,double y1,double x2,double y2,double x3,double y3)
{//Replace x,y variables by these numbers when loading from the file
    sf::ConvexShape Kicker; //غير اسم البتاعة ديه ل Kicker
    Kicker.setPointCount(3);
    Kicker.setPoint(0,sf::Vector2f (GAME_WIDTH-30-25,735.0));
    Kicker.setPoint(1,sf::Vector2f (GAME_WIDTH-30-130,850));
    Kicker.setPoint(2,sf::Vector2f (GAME_WIDTH-30-25,600));
    Kicker.setFillColor(sf::Color::Cyan);
    window.draw(Kicker);
}

void Interface::drawBackground()
{
    sf::RectangleShape Background(sf::Vector2f(GAME_WIDTH,GAME_HEIGHT));
    Background.setFillColor(backgroundColor);
    window.draw(Background);
}

void Interface::drawPortals(Vector2D Pos1, Vector2D Pos2,double radius) {
    sf::CircleShape circle1(radius),circle2(radius);
    circle1.setOrigin(radius, radius);
    circle1.setOutlineThickness(outlineThickness);
    circle1.setOutlineColor(RadiantColor);
    circle1.setFillColor(sf::Color::Transparent);

    circle2.setFillColor(sf::Color::Transparent);
    circle2.setOrigin(radius,radius);
    circle2.setOutlineThickness(outlineThickness);
    circle2.setOutlineColor(RadiantColor);

    circle1.setPosition(Pos1.x,Pos1.y);
    circle2.setPosition(Pos2.x,Pos2.y);
    window.draw(circle2);
    window.draw(circle1);

    //Sprite
    PortalSprite.setOrigin(PortalSprite.getTexture()->getSize().x/2.0,PortalSprite.getTexture()->getSize().y/2.0);
    PortalSprite.setPosition(Pos1.x,Pos1.y);
    PortalSprite.setScale(0.1,0.1);

    window.draw(PortalSprite);

    PortalSprite.setPosition(Pos2.x,Pos2.y);
    window.draw(PortalSprite);
}

void Interface::drawGate(double length,double width,Vector2D Center,bool AllowUp) {
    sf::RectangleShape UpperGate(sf::Vector2f (length,width/2.0)),
    LowerGate(sf::Vector2f(length,width/2.0));

    //Origin to center
    LowerGate.setOrigin(length/2.0,width/4.0);
    UpperGate.setOrigin(length/2.0,width/4.0);

    //Coloring
    if(AllowUp){
        UpperGate.setFillColor(outlineColor);
        LowerGate.setFillColor(RadiantColor);
    }else{
        UpperGate.setFillColor(RadiantColor);
        LowerGate.setFillColor(outlineColor);
    }

    UpperGate.setPosition(Center.x,Center.y-width/4.0);
    LowerGate.setPosition(Center.x,Center.y+width/4.0);
    window.draw(UpperGate);
    window.draw(LowerGate);
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

void Interface::drawCollectable(double radius, string L, Vector2D Center, bool Used) {
    sf::CircleShape Collectable(radius);
    if(Used){
        Collectable.setFillColor(RadiantColor);
    }else{
        Collectable.setFillColor(sf::Color::Transparent);
    }
    drawText(L, 30, {Center.x-radius/1.8,Center.y-radius*5/4});
    Collectable.setOrigin(radius,radius);
    Collectable.setPosition(Center.x,Center.y);
    Collectable.setOutlineThickness(2);
    Collectable.setOutlineColor(RadiantColor);
    window.draw(Collectable);
}

void Interface::drawSpeedBooster(double radius,Vector2D Center){
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

void Interface::drawSwitch(Vector2D Center, double Length,bool Used) {
    sf::RectangleShape line(sf::Vector2f(Length, 10));
    line.setOrigin(Length,5);
    line.setPosition(Center);
    if(Used){
        line.setFillColor(outlineColor);
    }else{
        line.setFillColor(RadiantColor);
    }
    window.draw(line);
}

void Interface::drawLane(double Length, Vector2D Center, double Width) {
    //Initializing
    sf::RectangleShape LeftLine(sf::Vector2f(5,Length)),RightLine(sf::Vector2f(5,Length));
    //Aesthetics
    LeftLine.setFillColor(outlineColor);
    RightLine.setFillColor(outlineColor);

    //Positioning
    LeftLine.setOrigin(2.5,Length/2.0);
    RightLine.setOrigin(2.5,Length/2.0);
    LeftLine.setPosition(Center.x-Width,Center.y);
    RightLine.setPosition(Center.x+Width,Center.y);

    //Drawing
    window.draw(LeftLine);
    window.draw(RightLine);
}

void Interface::drawUIBackground() {
    sf::RectangleShape Box(sf::Vector2f(WINDOW_WIDTH-GAME_WIDTH,GAME_HEIGHT));

    Box.setOrigin(0,0);
    Box.setPosition(GAME_WIDTH,0);
    Box.setFillColor(sf::Color(54,79,107));

    window.draw(Box);
}

sf::RenderWindow &Interface::GetWindow() {
    return window;
}

void Interface::drawBullseye(Vector2D Center,double Length, double Width, bool isVertical) {
    if (isVertical){
        sf::RectangleShape Ace(Vector2D{Width,Length/3.0}),
                Expert(Vector2D{Width,Length*2.0/3.0}),
                Novice(Vector2D{Width,Length});
        //Origin
        Ace.setOrigin(Width/2.0,Length/6.0);
        Expert.setOrigin(Width/2.0,Length/3.0);
        Novice.setOrigin(Width/2.0,Length/2.0);

        //Positioning
        Ace.setPosition(Center);
        Expert.setPosition(Center);
        Novice.setPosition(Center);

        //Aesthetics
        Ace.setFillColor(sf::Color(254, 255, 137));
        Expert.setFillColor(sf::Color(255, 159, 104));
        Novice.setFillColor(sf::Color(248, 89, 89));

        //Draw
        window.draw(Novice);
        window.draw(Expert);
        window.draw(Ace);
    }else{
        sf::RectangleShape Ace(Vector2D {Length/3.0,Width}),
                Expert(Vector2D {Length*2/3.0,Width}),
                Novice(Vector2D{Length,Width});
        //Origin
        Ace.setOrigin(Length/6.0,Width/2.0);
        Expert.setOrigin(Length/3.0,Width/2.0);
        Novice.setOrigin(Length/2.0,Width/2.0);

        //Positioning
        Ace.setPosition(Center);
        Expert.setPosition(Center);
        Novice.setPosition(Center);

        //Aesthetics
        Ace.setFillColor(sf::Color(254, 255, 137));
        Expert.setFillColor(sf::Color(255, 159, 104));
        Novice.setFillColor(sf::Color(248, 89, 89));

        //Draw
        window.draw(Novice);
        window.draw(Expert);
        window.draw(Ace);
    }
}

void Interface::drawPopBumper(Vector2D center, double radius, bool Hit) {
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(1.5 * outlineThickness);
    circle.setOutlineColor(outlineColor);

    circle.setPosition(center.x, center.y);
    if (!Hit){
        circle.setFillColor(RadiantColor);
    }else{
        circle.setFillColor(textColor);
    }
    window.draw(circle);
    Bumpersprite.setOrigin(Bumpersprite.getTexture()->getSize().x/2.0,Bumpersprite.getTexture()->getSize().y/2.0);
    Bumpersprite.setPosition(center.x , center.y);
    Bumpersprite.setScale(2, 2);
    window.draw(Bumpersprite);
}

void Interface::drawThrustBumper(Vector2D center, double radius, bool Hit) {
    sf::CircleShape circle(radius);
    ThrustSprite.setOrigin(ThrustSprite.getTexture()->getSize().x/2.0,ThrustSprite.getTexture()->getSize().y/2.0);
    ThrustSprite.setPosition(center.x, center.y);
    circle.setOrigin(radius,radius);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(1.5 * outlineThickness);
    circle.setOutlineColor(outlineColor);
    window.draw(circle);
    ThrustSprite.setScale(0.015, 0.015);
    window.draw(ThrustSprite);
}

void Interface::drawVibraniumBumper(Vector2D center, double radius,bool Hit) {
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(center.x, center.y);
    circle.setFillColor(sf::Color(8, 105, 114, 255));
    circle.setOutlineThickness(1.3 * outlineThickness);
    circle.setOutlineColor(sf::Color::Black);
    window.draw(circle);

    //drawing texture for 1st circle
    Vibraniumsprite.setOrigin(Vibraniumsprite.getTexture()->getSize().x/2.0,Vibraniumsprite.getTexture()->getSize().y/2.0);
    Vibraniumsprite.setPosition(center.x, center.y);
    Vibraniumsprite.setScale(0.4,0.4);
    window.draw(Vibraniumsprite);
}
