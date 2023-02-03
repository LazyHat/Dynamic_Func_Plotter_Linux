#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <array>

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

        std::map<State, std::array<Color, 3>> _colors =
            {{Normal, {{Color(150, 150, 150), Color::Black, Color::White}}},
             {Hovered, {{Color(120, 120, 200), Color::Black, Color::White}}},
             {Pressed, {{Color(100, 100, 100), Color::Black, Color::White}}}};

        virtual void draw(sf::RenderTarget &target, RenderStates states) const;

    public:
        Button();
        Button(Vector2f pos, Vector2f size, Font &font, std::string label = "But");
        void Update(Event &e, RenderWindow &window);
        void SetFont(Font &font);
        State GetState();
    };
}