#include "../include/Hangman.h"

void Hangman::draw(sf::RenderWindow& window, int mistakes) const
{
    drawScaffold(window);

    if (mistakes >= 1) drawHead(window);
    if (mistakes >= 2) drawTorso(window);
    if (mistakes >= 3) drawLeftArm(window);
    if (mistakes >= 4) drawRightArm(window);
    if (mistakes >= 5) drawLeftLeg(window);
    if (mistakes >= 6) drawRightLeg(window);
}

sf::Color Hangman::lineColor() const
{
    return sf::Color(232, 238, 246);
}

void Hangman::drawScaffold(sf::RenderWindow& window) const
{
    sf::RectangleShape vertical({6.f, 360.f});
    vertical.setPosition({180.f, 110.f});
    vertical.setFillColor(lineColor());
    window.draw(vertical);

    sf::RectangleShape top({260.f, 6.f});
    top.setPosition({180.f, 110.f});
    top.setFillColor(lineColor());
    window.draw(top);

    sf::RectangleShape rope({6.f, 55.f});
    rope.setPosition({410.f, 110.f});
    rope.setFillColor(lineColor());
    window.draw(rope);

    sf::RectangleShape base({330.f, 6.f});
    base.setPosition({95.f, 470.f});
    base.setFillColor(lineColor());
    window.draw(base);
}

void Hangman::drawHead(sf::RenderWindow& window) const
{
    sf::CircleShape head(42.f);
    head.setPosition({371.f, 165.f});
    head.setFillColor(sf::Color::Transparent);
    head.setOutlineColor(lineColor());
    head.setOutlineThickness(6.f);
    window.draw(head);
}

void Hangman::drawTorso(sf::RenderWindow& window) const
{
    sf::RectangleShape torso({6.f, 125.f});
    torso.setPosition({407.f, 249.f});
    torso.setFillColor(lineColor());
    window.draw(torso);
}

void Hangman::drawLeftArm(sf::RenderWindow& window) const
{
    sf::RectangleShape arm({6.f, 105.f});
    arm.setPosition({410.f, 260.f});
    arm.setRotation(sf::degrees(-48.f));
    arm.setFillColor(lineColor());
    window.draw(arm);
}

void Hangman::drawRightArm(sf::RenderWindow& window) const
{
    sf::RectangleShape arm({6.f, 105.f});
    arm.setPosition({410.f, 260.f});
    arm.setRotation(sf::degrees(48.f));
    arm.setFillColor(lineColor());
    window.draw(arm);
}

void Hangman::drawLeftLeg(sf::RenderWindow& window) const
{
    sf::RectangleShape leg({6.f, 125.f});
    leg.setPosition({410.f, 365.f});
    leg.setRotation(sf::degrees(-34.f));
    leg.setFillColor(lineColor());
    window.draw(leg);
}

void Hangman::drawRightLeg(sf::RenderWindow& window) const
{
    sf::RectangleShape leg({6.f, 125.f});
    leg.setPosition({410.f, 365.f});
    leg.setRotation(sf::degrees(34.f));
    leg.setFillColor(lineColor());
    window.draw(leg);
}
