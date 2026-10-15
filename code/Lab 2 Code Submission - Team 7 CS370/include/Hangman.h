#pragma once

#include <SFML/Graphics.hpp>

class Hangman
{
public:
    void draw(sf::RenderWindow& window, int mistakes) const;

private:
    void drawScaffold(sf::RenderWindow& window) const;
    void drawHead(sf::RenderWindow& window) const;
    void drawTorso(sf::RenderWindow& window) const;
    void drawLeftArm(sf::RenderWindow& window) const;
    void drawRightArm(sf::RenderWindow& window) const;
    void drawLeftLeg(sf::RenderWindow& window) const;
    void drawRightLeg(sf::RenderWindow& window) const;

    sf::Color lineColor() const;
};
