#include "Button.h"

sf::Button::Button() {}

sf::Button::Button(sf::Vector2f pos, sf::Vector2f size, sf::Font &font)
{
    _border.setPosition(pos);
    _border.setSize(size);
    _border.setFillColor(_colors[Normal][0]);
    _border.setOutlineThickness(-1.4);
    _border.setOutlineColor(_colors[Normal][1]);
    _label.setFont(font);
    _label.setCharacterSize(14);
    _label.setString("But1");
    _label.setOrigin(_label.getGlobalBounds().width / 2, _label.getGlobalBounds().height / 2);
    _label.setPosition(pos.x + size.x / 2, pos.y + size.y / 2);
    _label.setFillColor(_colors[Normal][2]);
}

void sf::Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_border, states);
    target.draw(_label, states);
}

void sf::Button::Update(sf::Event &e, sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    bool mouseState = (mousePos.x >= _border.getPosition().x &&
                       mousePos.x <= _border.getPosition().x + _border.getSize().x &&
                       mousePos.y >= _border.getPosition().y &&
                       mousePos.y <= _border.getPosition().y + _border.getSize().y);

    if (e.type == Event::MouseMoved)
    {
        if (mouseState)
            _state = Hovered;
        else
            _state = Normal;
    }
    else if (e.type == Event::MouseButtonPressed)
    {
        if (mouseState && e.mouseButton.button == Mouse::Left)
            _state = Pressed;
        else
            _state = Normal;
    }
    else if (e.type == Event::MouseButtonReleased)
    {
        if (mouseState && e.mouseButton.button == Mouse::Left)
            _state = Hovered;
        else
            _state = Normal;
    }
    _border.setFillColor(_colors[_state][0]);
    _border.setOutlineColor(_colors[_state][1]);
    _label.setFillColor(_colors[_state][2]);
}

void sf::Button::SetFont(sf::Font &font)
{
    _label.setFont(font);
}

sf::Button::State sf::Button::GetState()
{
    return _state;
}