#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <string>

class Button
{
public:
    Button() = default;

    Button(const sf::Font& font,
           const std::string& label,
           sf::Vector2f position,
           sf::Vector2f size,
           unsigned int characterSize = 24);

    void setLabel(const std::string& label);
    void setPosition(sf::Vector2f position);
    void setSize(sf::Vector2f size);

    void update(sf::Vector2f mousePosition);
    void draw(sf::RenderWindow& window) const;

    bool contains(sf::Vector2f point) const;
    bool wasClicked(sf::Vector2f point) const;

private:
    void centerText();

    const sf::Font* font_{nullptr};
    sf::RectangleShape shape_;
    std::optional<sf::Text> text_;
    bool hovered_{false};
};
