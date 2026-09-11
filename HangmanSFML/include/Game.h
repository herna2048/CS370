#pragma once

#include "WordDatabase.h"

#include <string>
#include <vector>

class Game
{
public:
    static constexpr int MaxMistakes = 6;

    Game();

    void start(Category category);
    bool guess(char letter);

    bool hasStarted() const;
    bool isWon() const;
    bool isLost() const;
    bool isOver() const;

    Category getCategory() const;
    const std::string& getWord() const;
    const std::string& getDisplayWord() const;
    const std::vector<char>& getCorrectLetters() const;
    const std::vector<char>& getIncorrectLetters() const;

    int getMistakes() const;
    int getRemainingGuesses() const;

private:
    static char normalize(char letter);
    void rebuildDisplayWord();

    Category category_{Category::Animals};
    std::string word_;
    std::string displayWord_;
    std::vector<char> correctLetters_;
    std::vector<char> incorrectLetters_;
    int mistakes_{0};
    bool started_{false};
};
