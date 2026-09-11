#pragma once

#include "Button.h"
#include "Game.h"
#include "Hangman.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

enum class Screen
{
    CategorySelection,
    Game,
    GameOver
};

class UI
{
public:
    explicit UI(const sf::Font& font);

    void handleMouse(sf::Vector2f mousePosition, bool pressed, Game& game, Screen& screen);
    void handleKey(sf::Keyboard::Key key, Game& game, Screen& screen);

    void draw(sf::RenderWindow& window, const Game& game, Screen screen);

private:
    void drawCategoryScreen(sf::RenderWindow& window);
    void drawGameScreen(sf::RenderWindow& window, const Game& game);
    void drawGameOverScreen(sf::RenderWindow& window, const Game& game);

    void drawHeader(sf::RenderWindow& window, const std::string& title) const;
    void drawText(sf::RenderWindow& window,
                  const std::string& text,
                  sf::Vector2f position,
                  unsigned int size,
                  sf::Color color = sf::Color::White) const;
    void drawCenteredText(sf::RenderWindow& window,
                          const std::string& text,
                          float y,
                          unsigned int size,
                          sf::Color color = sf::Color::White) const;

    void createCategoryButtons();
    void createGameButtons();
    void createGameOverButtons();

    const sf::Font& font_;
    Hangman hangman_;

    Button animalsButton_;
    Button foodButton_;
    Button statesButton_;
    Button countriesButton_;

    Button newGameButton_;
    Button menuButton_;
    Button playAgainButton_;
    Button quitButton_;

    sf::Vector2f lastMousePosition_{0.f, 0.f};
};
