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
}

TextBox::TextBox() {}

void TextBox::SetFont(Font &font)
{
    _text.setFont(font);
}
