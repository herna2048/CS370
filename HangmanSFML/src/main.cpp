#include "../include/Game.h"
#include "../include/UI.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace
{
bool loadFont(sf::Font& font)
{
    const std::string fontPath = "assets/fonts/OpenSans-Regular.ttf";

    if (font.openFromFile(fontPath))
        return true;

    // A few common fallback locations make the project easier to run
    // when the bundled/downloaded font is not present.
    const std::string fallbacks[] = {
        "/System/Library/Fonts/Supplemental/Arial.ttf",
        "/Library/Fonts/Arial.ttf",
        "C:/Windows/Fonts/arial.ttf",
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"
    };

    for (const auto& path : fallbacks)
    {
        if (font.openFromFile(path))
            return true;
    }

    return false;
}
}

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({1280, 720}),
        "Hangman"
    );

    window.setFramerateLimit(60);

    sf::Font font;
    if (!loadFont(font))
    {
        std::cerr
            << "Unable to load a font. Place a .ttf/.otf font at "
            << "assets/fonts/OpenSans-Regular.ttf.\n";
        return 1;
    }

    Game game;
    Screen screen = Screen::CategorySelection;
    UI ui(font);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Escape)
                {
                    if (screen == Screen::Game)
                        screen = Screen::CategorySelection;
                    else
                        window.close();
                }
                else
                {
                    ui.handleKey(keyPressed->code, game, screen);
                }
            }
            else if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                ui.handleMouse(
                    window.mapPixelToCoords(mouseMoved->position),
                    false,
                    game,
                    screen
                );
            }
            else if (const auto* mousePressed =
                         event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mousePressed->button == sf::Mouse::Button::Left)
                {
                    ui.handleMouse(
                        window.mapPixelToCoords(mousePressed->position),
                        true,
                        game,
                        screen
                    );
                }
            }
        }

        ui.draw(window, game, screen);
    }

    return 0;
}
