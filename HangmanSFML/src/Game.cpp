#include "../include/Game.h"

#include <algorithm>
#include <cctype>

Game::Game()
{
    start(Category::Animals);
}

char Game::normalize(char letter)
{
    return static_cast<char>(
        std::toupper(static_cast<unsigned char>(letter))
    );
}

void Game::start(Category category)
{
    category_ = category;
    word_ = WordDatabase::getRandomWord(category_);
    displayWord_.assign(word_.size(), '_');

    correctLetters_.clear();
    incorrectLetters_.clear();
    mistakes_ = 0;
    started_ = true;

    rebuildDisplayWord();
}

bool Game::guess(char letter)
{
    if (!started_ || isOver())
        return false;

    letter = normalize(letter);

    if (letter < 'A' || letter > 'Z')
        return false;

    if (std::find(correctLetters_.begin(), correctLetters_.end(), letter) != correctLetters_.end() ||
        std::find(incorrectLetters_.begin(), incorrectLetters_.end(), letter) != incorrectLetters_.end())
    {
        return false;
    }

    if (word_.find(letter) != std::string::npos)
    {
        correctLetters_.push_back(letter);
        rebuildDisplayWord();
        return true;
    }

    incorrectLetters_.push_back(letter);
    ++mistakes_;
    return false;
}

void Game::rebuildDisplayWord()
{
    displayWord_.clear();

    for (char character : word_)
    {
        if (std::find(correctLetters_.begin(), correctLetters_.end(), character) != correctLetters_.end())
            displayWord_ += character;
        else
            displayWord_ += '_';
    }
}

bool Game::hasStarted() const
{
    return started_;
}

bool Game::isWon() const
{
    return started_ && displayWord_ == word_;
}

bool Game::isLost() const
{
    return started_ && mistakes_ >= MaxMistakes && !isWon();
}

bool Game::isOver() const
{
    return isWon() || isLost();
}

Category Game::getCategory() const
{
    return category_;
}

const std::string& Game::getWord() const
{
    return word_;
}

const std::string& Game::getDisplayWord() const
{
    return displayWord_;
}

const std::vector<char>& Game::getCorrectLetters() const
{
    return correctLetters_;
}

const std::vector<char>& Game::getIncorrectLetters() const
{
    return incorrectLetters_;
}

int Game::getMistakes() const
{
    return mistakes_;
}

int Game::getRemainingGuesses() const
{
    return MaxMistakes - mistakes_;
}
