#pragma once
#include <SFML/Graphics.hpp>

class Button : sf::Drawable
{
    enum Style
    {

    };
    enum State
    {

    };
    sf::RectangleShape button;
    sf::Font font;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    Button(sf::Vector2f pos, sf::Vector2f size);
};