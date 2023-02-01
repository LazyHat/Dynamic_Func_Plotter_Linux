#pragma once
#include <SFML/Graphics.hpp>
#include <map>

namespace sf
{
    class Button : public Drawable
    {
    public:
        enum State
        {
            Normal,
            Hovered,
            Pressed,
            Holded,
            Released
        };

    private:
        RectangleShape _border;
        Text _label;
        State _state = Released;

        std::map<State, Color[3]> colors = {{Normal, Color[3]{Color::Black, Color::Blue, Color::Magenta}}};
        Color _pressed[2]{Color::Magenta, Color::Yellow};
        Color _normal[2]{Color::Black, Color::White};
        Color _hovered[2]{Color::Cyan, Color::Blue};

        virtual void draw(sf::RenderTarget &target, RenderStates states) const;

    public:
        Button();
        Button(Vector2f pos, Vector2f size, Font &font);
        void Update(Event &e, RenderWindow &window);
        void SetFont(Font &font);
        State GetState();
    };
}