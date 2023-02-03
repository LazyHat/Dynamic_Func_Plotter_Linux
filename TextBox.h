#include <SFML/Graphics.hpp>
#include "Button.h"

namespace sf
{
    class TextBox : public Drawable
    {
        RectangleShape _border;
        Text _text;

    public:
        virtual void draw(RenderTarget &target, RenderStates states) const;
        TextBox(Vector2f pos, Vector2f size, Font &font);
        TextBox();
        void SetFont(Font &font);
    };
}