#include "../include/WordDatabase.h"

#include <random>
#include <stdexcept>

namespace
{
std::string chooseRandom(const std::vector<std::string>& words)
{
    static std::random_device device;
    static std::mt19937 generator(device());
    std::uniform_int_distribution<std::size_t> distribution(0, words.size() - 1);
    return words[distribution(generator)];
}
}

const std::vector<std::string>& WordDatabase::animals()
{
    static const std::vector<std::string> words = {
        "ALLIGATOR", "ANTELOPE", "BADGER", "BEAR", "BEAVER",
        "BUFFALO", "BUTTERFLY", "CAMEL", "CHEETAH", "CHIMPANZEE",
        "COUGAR", "CROCODILE", "DOLPHIN", "DONKEY", "EAGLE",
        "ELEPHANT", "FALCON", "FLAMINGO", "FOX", "FROG",
        "GIRAFFE", "GORILLA", "HAMSTER", "HEDGEHOG", "HIPPOPOTAMUS",
        "HORSE", "HYENA", "IGUANA", "JAGUAR", "KANGAROO",
        "KOALA", "LEMUR", "LEOPARD", "LION", "LOBSTER",
        "MEERKAT", "MONKEY", "OCTOPUS", "OSTRICH", "OTTER",
        "PANDA", "PARROT", "PELICAN", "PENGUIN", "PORCUPINE",
        "RACCOON", "RHINOCEROS", "SHARK", "SLOTH", "SQUIRREL",
        "TIGER", "TURTLE", "WALRUS", "WOLF", "ZEBRA"
    };
    return words;
}

const std::vector<std::string>& WordDatabase::food()
{
    static const std::vector<std::string> words = {
        "APPLE", "AVOCADO", "BACON", "BAGEL", "BANANA",
        "BURRITO", "BURGER", "CAKE", "CEREAL", "CHEESE",
        "CHEESECAKE", "CHICKEN", "CHOCOLATE", "COOKIE", "CUPCAKE",
        "DUMPLINGS", "ENCHILADA", "FRENCHFRIES", "GRAPES", "HOTDOG",
        "ICECREAM", "LASAGNA", "LEMONADE", "MACARONI", "MANGO",
        "MEATBALL", "MILKSHAKE", "NACHOS", "NOODLES", "OMELET",
        "ORANGE", "PANCAKES", "PASTA", "PEACH", "PEANUTBUTTER",
        "PEPPERONI", "PICKLES", "PIZZA", "POPCORN", "PRETZEL",
        "PUMPKIN", "RAVIOLI", "SANDWICH", "SAUSAGE", "SMOOTHIE",
        "SPAGHETTI", "STRAWBERRY", "TACO", "WAFFLES", "WATERMELON"
    };
    return words;
}

const std::vector<std::string>& WordDatabase::states()
{
    static const std::vector<std::string> words = {
        "ALABAMA", "ALASKA", "ARIZONA", "ARKANSAS", "CALIFORNIA",
        "COLORADO", "CONNECTICUT", "DELAWARE", "FLORIDA", "GEORGIA",
        "HAWAII", "IDAHO", "ILLINOIS", "INDIANA", "IOWA",
        "KANSAS", "KENTUCKY", "LOUISIANA", "MAINE", "MARYLAND",
        "MASSACHUSETTS", "MICHIGAN", "MINNESOTA", "MISSISSIPPI", "MISSOURI",
        "MONTANA", "NEBRASKA", "NEVADA", "NEWHAMPSHIRE", "NEWJERSEY",
        "NEWMEXICO", "NEWYORK", "NORTHCAROLINA", "NORTHDAKOTA", "OHIO",
        "OKLAHOMA", "OREGON", "PENNSYLVANIA", "RHODEISLAND", "SOUTHCAROLINA",
        "SOUTHDAKOTA", "TENNESSEE", "TEXAS", "UTAH", "VERMONT",
        "VIRGINIA", "WASHINGTON", "WESTVIRGINIA", "WISCONSIN", "WYOMING"
    };
    return words;
}

const std::vector<std::string>& WordDatabase::countries()
{
    static const std::vector<std::string> words = {
        "ARGENTINA", "AUSTRALIA", "AUSTRIA", "BELGIUM", "BRAZIL",
        "CANADA", "CHILE", "CHINA", "COLOMBIA", "CROATIA",
        "DENMARK", "EGYPT", "FINLAND", "FRANCE", "GERMANY",
        "GREECE", "ICELAND", "INDIA", "INDONESIA", "IRELAND",
        "ISRAEL", "ITALY", "JAMAICA", "JAPAN", "KENYA",
        "MALAYSIA", "MEXICO", "MOROCCO", "NETHERLANDS", "NEWZEALAND",
        "NORWAY", "PAKISTAN", "PERU", "PHILIPPINES", "POLAND",
        "PORTUGAL", "QATAR", "ROMANIA", "SINGAPORE", "SOUTHAFRICA",
        "SOUTHKOREA", "SPAIN", "SWEDEN", "SWITZERLAND", "THAILAND",
        "TURKEY", "UKRAINE", "UNITEDKINGDOM", "UNITEDSTATES", "VIETNAM"
    };
    return words;
}

std::string WordDatabase::getRandomWord(Category category)
{
    switch (category)
    {
        case Category::Animals:   return chooseRandom(animals());
        case Category::Food:      return chooseRandom(food());
        case Category::States:    return chooseRandom(states());
        case Category::Countries: return chooseRandom(countries());
    }

    throw std::invalid_argument("Unknown category.");
}

std::string WordDatabase::categoryName(Category category)
{
    switch (category)
    {
        case Category::Animals:   return "ANIMALS";
        case Category::Food:      return "FOOD";
        case Category::States:    return "U.S. STATES";
        case Category::Countries: return "COUNTRIES";
    }

    return "UNKNOWN";
}
