#include "Button.h"

Button::Button(sf::Vector2f pos, sf::Vector2f size)
{
    button.setPosition(pos);
    button.setSize(size);
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(button, states);
}