#include "TextBox.h"

using namespace sf;
void TextBox::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(_border, states);
    target.draw(_text, states);
}

TextBox::TextBox(Vector2f pos, Vector2f size, Font &font)
{
    _text.setFont(font);
    _border.setPosition(pos);
    _border.setSize(size);
    _text.setPosition(pos);
    _text.setCharacterSize(20);
    _text.setFillColor(Color::Black);
}

TextBox::TextBox()
{
    _text.setFillColor(Color::Black);
    _text.setCharacterSize(20);
}

void TextBox::Display(std::list<std::string> src)
{
    std::string result = "";
    for (auto s : src)
    {
        result += s + "\n";
    }
    _text.setString(result);
}

void TextBox::SetFont(Font &font) { _text.setFont(font); }

void TextBox::SetPosition(Vector2f pos)
{
    _border.setPosition(pos);
    _text.setPosition(pos);
}

void TextBox::SetSize(Vector2f size) { _border.setSize(size); }
