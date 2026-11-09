#include "../include/Button.h"

Button::Button(const sf::Font& font,
               const std::string& label,
               sf::Vector2f position,
               sf::Vector2f size,
               unsigned int characterSize)
    : font_(&font),
      shape_(size),
      text_(std::in_place, font, label, characterSize)
{
    shape_.setPosition(position);
    centerText();
}

void Button::setLabel(const std::string& label)
{
    if (text_)
        text_->setString(label);

    centerText();
}

void Button::setPosition(sf::Vector2f position)
{
    shape_.setPosition(position);
    centerText();
}

void Button::setSize(sf::Vector2f size)
{
    shape_.setSize(size);
    centerText();
}

void Button::update(sf::Vector2f mousePosition)
{
    hovered_ = contains(mousePosition);

    if (hovered_)
    {
        shape_.setFillColor(sf::Color(50, 70, 95));
        shape_.setOutlineColor(sf::Color(90, 170, 255));
    }
    else
    {
        shape_.setFillColor(sf::Color(31, 45, 62));
        shape_.setOutlineColor(sf::Color(64, 82, 104));
    }

    shape_.setOutlineThickness(2.f);
}

void Button::draw(sf::RenderWindow& window) const
{
    window.draw(shape_);

    if (text_)
        window.draw(*text_);
}

bool Button::contains(sf::Vector2f point) const
{
    return shape_.getGlobalBounds().contains(point);
}

bool Button::wasClicked(sf::Vector2f point) const
{
    return contains(point);
}

void Button::centerText()
{
    if (!text_)
        return;

    const auto bounds = text_->getLocalBounds();
    const auto buttonBounds = shape_.getGlobalBounds();

    text_->setOrigin({
        bounds.position.x + bounds.size.x / 2.f,
        bounds.position.y + bounds.size.y / 2.f
    });

    text_->setPosition({
        buttonBounds.position.x + buttonBounds.size.x / 2.f,
        buttonBounds.position.y + buttonBounds.size.y / 2.f
    });

    text_->setFillColor(sf::Color(240, 244, 248));
}
