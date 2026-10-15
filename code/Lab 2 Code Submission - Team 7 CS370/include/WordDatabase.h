#pragma once

#include <string>
#include <vector>

enum class Category
{
    Animals,
    Food,
    States,
    Countries
};

class WordDatabase
{
public:
    static std::string getRandomWord(Category category);
    static std::string categoryName(Category category);

private:
    static const std::vector<std::string>& animals();
    static const std::vector<std::string>& food();
    static const std::vector<std::string>& states();
    static const std::vector<std::string>& countries();
};
