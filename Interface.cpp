#include "Interface.h"


Interface::Interface()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;  // Remove this line if the game was too laggy
    window.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Pinball", sf::Style::Titlebar, settings);
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(0);
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

void Interface::drawBumper(Vector2D center, float radius) {
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setOutlineThickness(1.5*outlineThickness);
    circle.setOutlineColor(sf::Color::Magenta);
    circle.setFillColor(ballFillColor);
    circle.setPosition(center.x, center.y);
    window.draw(circle);

    //Sprite draw
    Bumpersprite.setTexture(Bumpertexture);
    Bumpersprite.setPosition(center.x-(radius/2)-15,center.y-(radius/2)-15);
    Bumpersprite.setScale(2,2);
    window.draw(Bumpersprite);
}

void Interface::drawFPS() {
    if(!font.loadFromFile("Assets/Fonts/BebasNeue-Regular.ttf")){
        cout<< "Can't load font! "<< endl;
    }

    text.setFont(font);
    text.setString(FPS);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);
    text.setPosition(0,0);
    window.draw(text);
}

void Interface::setFPS(string fps) {
    FPS=fps;
}

void Interface::drawText(string Fontpath, string Text, int FontSize, sf::Color color, Vector2D position) {
    if(!font.loadFromFile(Fontpath)){
        cout<< "Can't load font! "<< endl;
    }
    text.setFont(font);
    text.setString(Text);
    sf::FloatRect bounds=text.getLocalBounds();
    text.setCharacterSize(FontSize);
    text.setFillColor(color);
    text.setPosition(position.x-bounds.width/2,position.y);
    window.draw(text);
}

void Interface::LoadGraphics() {
    //Loading Ball sprite
    if (!Balltexture.loadFromFile("Assets/Sprites/pokeball.png")) {
        // error...
        cout << "Error loading pokeball!" << endl;
    }

    //Loading Bumper sprite
    if(!Bumpertexture.loadFromFile("Assets/Sprites/PokeBumper.png")){
        cout << "Error loading Bumper sprite!" <<  endl;
    }

}




