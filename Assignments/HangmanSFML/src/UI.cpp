#include "../include/UI.h"

#include <algorithm>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace
{
const sf::Color Background(14, 20, 29);
const sf::Color Panel(22, 31, 44);
const sf::Color Accent(90, 170, 255);
const sf::Color Success(75, 210, 145);
const sf::Color Error(245, 95, 95);
const sf::Color Muted(150, 164, 180);

// The game logic stores multi-word answers without spaces so keyboard guesses
// remain simple. This map restores the natural word boundaries for the UI.
std::string formatAnswer(const std::string& word)
{
    static const std::vector<std::pair<std::string, std::string>> spacedWords = {
        {"FRENCHFRIES", "FRENCH FRIES"},
        {"HOTDOG", "HOT DOG"},
        {"ICECREAM", "ICE CREAM"},
        {"PEANUTBUTTER", "PEANUT BUTTER"},
        {"NEWJERSEY", "NEW JERSEY"},
        {"NEWMEXICO", "NEW MEXICO"},
        {"NEWYORK", "NEW YORK"},
        {"NORTHCAROLINA", "NORTH CAROLINA"},
        {"NORTHDAKOTA", "NORTH DAKOTA"},
        {"RHODEISLAND", "RHODE ISLAND"},
        {"SOUTHCAROLINA", "SOUTH CAROLINA"},
        {"SOUTHDAKOTA", "SOUTH DAKOTA"},
        {"WESTVIRGINIA", "WEST VIRGINIA"},
        {"NEWZEALAND", "NEW ZEALAND"},
        {"SOUTHAFRICA", "SOUTH AFRICA"},
        {"SOUTHKOREA", "SOUTH KOREA"},
        {"UNITEDKINGDOM", "UNITED KINGDOM"},
        {"UNITEDSTATES", "UNITED STATES"}
    };

    for (const auto& [compact, spaced] : spacedWords)
    {
        if (word == compact)
            return spaced;
    }

    return word;
}

std::string formatDisplayPattern(const std::string& word, const std::string& displayWord)
{
    const std::string formattedWord = formatAnswer(word);
    std::string result;
    std::size_t letterIndex = 0;

    for (char character : formattedWord)
    {
        if (character == ' ')
        {
            result += ' ';
        }
        else
        {
            result += displayWord.at(letterIndex++);
        }
    }

    return result;
}
}

UI::UI(const sf::Font& font)
    : font_(font)
{
    createCategoryButtons();
    createGameButtons();
    createGameOverButtons();
}

void UI::createCategoryButtons()
{
    const sf::Vector2f size(250.f, 95.f);

    animalsButton_ = Button(font_, "ANIMALS", {175.f, 190.f}, size, 25);
    foodButton_ = Button(font_, "FOOD", {455.f, 190.f}, size, 25);
    statesButton_ = Button(font_, "U.S. STATES", {175.f, 315.f}, size, 25);
    countriesButton_ = Button(font_, "COUNTRIES", {455.f, 315.f}, size, 25);
}

void UI::createGameButtons()
{
    newGameButton_ = Button(font_, "NEW GAME", {780.f, 610.f}, {180.f, 52.f}, 18);
    menuButton_ = Button(font_, "CATEGORY MENU", {975.f, 610.f}, {205.f, 52.f}, 18);
}

void UI::createGameOverButtons()
{
    playAgainButton_ = Button(font_, "PLAY AGAIN", {430.f, 495.f}, {190.f, 60.f}, 21);
    quitButton_ = Button(font_, "CATEGORY MENU", {650.f, 495.f}, {210.f, 60.f}, 21);
}

void UI::handleMouse(sf::Vector2f mousePosition,
                     bool pressed,
                     Game& game,
                     Screen& screen)
{
    lastMousePosition_ = mousePosition;

    animalsButton_.update(mousePosition);
    foodButton_.update(mousePosition);
    statesButton_.update(mousePosition);
    countriesButton_.update(mousePosition);
    newGameButton_.update(mousePosition);
    menuButton_.update(mousePosition);
    playAgainButton_.update(mousePosition);
    quitButton_.update(mousePosition);

    if (!pressed)
        return;

    if (screen == Screen::CategorySelection)
    {
        if (animalsButton_.wasClicked(mousePosition))
        {
            game.start(Category::Animals);
            screen = Screen::Game;
        }
        else if (foodButton_.wasClicked(mousePosition))
        {
            game.start(Category::Food);
            screen = Screen::Game;
        }
        else if (statesButton_.wasClicked(mousePosition))
        {
            game.start(Category::States);
            screen = Screen::Game;
        }
        else if (countriesButton_.wasClicked(mousePosition))
        {
            game.start(Category::Countries);
            screen = Screen::Game;
        }
    }
    else if (screen == Screen::Game)
    {
        if (newGameButton_.wasClicked(mousePosition))
        {
            game.start(game.getCategory());
        }
        else if (menuButton_.wasClicked(mousePosition))
        {
            screen = Screen::CategorySelection;
        }
    }
    else if (screen == Screen::GameOver)
    {
        if (playAgainButton_.wasClicked(mousePosition))
        {
            game.start(game.getCategory());
            screen = Screen::Game;
        }
        else if (quitButton_.wasClicked(mousePosition))
        {
            screen = Screen::CategorySelection;
        }
    }
}

void UI::handleKey(sf::Keyboard::Key key, Game& game, Screen& screen)
{
    if (screen != Screen::Game || game.isOver())
        return;

    // Handle the alphabet explicitly so this remains safe even if
    // SFML changes the underlying enum values in a future release.
    char letter = '\0';

    switch (key)
    {
        case sf::Keyboard::Key::A: letter = 'A'; break;
        case sf::Keyboard::Key::B: letter = 'B'; break;
        case sf::Keyboard::Key::C: letter = 'C'; break;
        case sf::Keyboard::Key::D: letter = 'D'; break;
        case sf::Keyboard::Key::E: letter = 'E'; break;
        case sf::Keyboard::Key::F: letter = 'F'; break;
        case sf::Keyboard::Key::G: letter = 'G'; break;
        case sf::Keyboard::Key::H: letter = 'H'; break;
        case sf::Keyboard::Key::I: letter = 'I'; break;
        case sf::Keyboard::Key::J: letter = 'J'; break;
        case sf::Keyboard::Key::K: letter = 'K'; break;
        case sf::Keyboard::Key::L: letter = 'L'; break;
        case sf::Keyboard::Key::M: letter = 'M'; break;
        case sf::Keyboard::Key::N: letter = 'N'; break;
        case sf::Keyboard::Key::O: letter = 'O'; break;
        case sf::Keyboard::Key::P: letter = 'P'; break;
        case sf::Keyboard::Key::Q: letter = 'Q'; break;
        case sf::Keyboard::Key::R: letter = 'R'; break;
        case sf::Keyboard::Key::S: letter = 'S'; break;
        case sf::Keyboard::Key::T: letter = 'T'; break;
        case sf::Keyboard::Key::U: letter = 'U'; break;
        case sf::Keyboard::Key::V: letter = 'V'; break;
        case sf::Keyboard::Key::W: letter = 'W'; break;
        case sf::Keyboard::Key::X: letter = 'X'; break;
        case sf::Keyboard::Key::Y: letter = 'Y'; break;
        case sf::Keyboard::Key::Z: letter = 'Z'; break;
        default: break;
    }

    if (letter != '\0')
    {
        game.guess(letter);

        if (game.isOver())
            screen = Screen::GameOver;
    }
}

void UI::draw(sf::RenderWindow& window, const Game& game, Screen screen)
{
    window.clear(Background);

    switch (screen)
    {
        case Screen::CategorySelection:
            drawCategoryScreen(window);
            break;

        case Screen::Game:
            drawGameScreen(window, game);
            break;

        case Screen::GameOver:
            drawGameOverScreen(window, game);
            break;
    }

    window.display();
}

void UI::drawHeader(sf::RenderWindow& window, const std::string& title) const
{
    drawCenteredText(window, title, 45.f, 34, sf::Color(240, 244, 248));
}

void UI::drawCategoryScreen(sf::RenderWindow& window)
{
    drawHeader(window, "HANGMAN");

    drawCenteredText(
        window,
        "Choose a category to begin",
        105.f,
        19,
        Muted
    );

    animalsButton_.draw(window);
    foodButton_.draw(window);
    statesButton_.draw(window);
    countriesButton_.draw(window);

    drawCenteredText(
        window,
        "6 mistakes allowed  •  Use your keyboard to guess letters",
        540.f,
        16,
        Muted
    );
}

void UI::drawGameScreen(sf::RenderWindow& window, const Game& game)
{
    drawHeader(window, WordDatabase::categoryName(game.getCategory()));

    sf::RectangleShape gamePanel({1120.f, 470.f});
    gamePanel.setPosition({40.f, 90.f});
    gamePanel.setFillColor(Panel);
    gamePanel.setOutlineColor(sf::Color(42, 57, 75));
    gamePanel.setOutlineThickness(2.f);
    window.draw(gamePanel);

    hangman_.draw(window, game.getMistakes());

    // Word display. Multi-word answers show a visible space between words.
    const std::string displayPattern =
        formatDisplayPattern(game.getWord(), game.getDisplayWord());

    drawCenteredText(window, displayPattern, 520.f, 34, sf::Color(245, 247, 250));

    drawText(
        window,
        "CORRECT",
        {770.f, 145.f},
        17,
        Success
    );

    std::string correct;
    for (char letter : game.getCorrectLetters())
    {
        correct += letter;
        correct += "   ";
    }

    if (correct.empty())
        correct = "—";

    drawText(window, correct, {770.f, 180.f}, 22);

    drawText(
        window,
        "INCORRECT",
        {770.f, 235.f},
        17,
        Error
    );

    std::string incorrect;
    for (char letter : game.getIncorrectLetters())
    {
        incorrect += letter;
        incorrect += "   ";
    }

    if (incorrect.empty())
        incorrect = "—";

    drawText(window, incorrect, {770.f, 270.f}, 22);

    drawText(
        window,
        "MISTAKES",
        {770.f, 330.f},
        17,
        Muted
    );

    std::ostringstream mistakes;
    mistakes << game.getMistakes() << " / " << Game::MaxMistakes;

    drawText(window, mistakes.str(), {770.f, 365.f}, 28);

    drawText(
        window,
        "Type a letter on your keyboard",
        {770.f, 420.f},
        16,
        Muted
    );

    newGameButton_.draw(window);
    menuButton_.draw(window);
}

void UI::drawGameOverScreen(sf::RenderWindow& window, const Game& game)
{
    drawHeader(window, game.isWon() ? "YOU WIN!" : "GAME OVER");

    sf::RectangleShape panel({700.f, 390.f});
    panel.setPosition({290.f, 110.f});
    panel.setFillColor(Panel);
    panel.setOutlineColor(game.isWon() ? Success : Error);
    panel.setOutlineThickness(3.f);
    window.draw(panel);

    drawCenteredText(
        window,
        game.isWon() ? "Great job!" : "Better luck next time!",
        170.f,
        25,
        game.isWon() ? Success : Error
    );

    drawCenteredText(window, "The word was", 235.f, 18, Muted);
    drawCenteredText(window, formatAnswer(game.getWord()), 280.f, 34);

    std::ostringstream score;
    score << "Mistakes: " << game.getMistakes() << " / " << Game::MaxMistakes;

    drawCenteredText(window, score.str(), 345.f, 18, Muted);

    playAgainButton_.draw(window);
    quitButton_.draw(window);
}

void UI::drawText(sf::RenderWindow& window,
                  const std::string& text,
                  sf::Vector2f position,
                  unsigned int size,
                  sf::Color color) const
{
    sf::Text drawable(font_, text, size);
    drawable.setPosition(position);
    drawable.setFillColor(color);
    window.draw(drawable);
}

void UI::drawCenteredText(sf::RenderWindow& window,
                          const std::string& text,
                          float y,
                          unsigned int size,
                          sf::Color color) const
{
    sf::Text drawable(font_, text, size);
    const auto bounds = drawable.getLocalBounds();

    drawable.setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
    });

    drawable.setPosition({640.f, y});
    drawable.setFillColor(color);

    window.draw(drawable);
}
