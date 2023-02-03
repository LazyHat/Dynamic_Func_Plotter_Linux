#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Stack.h"
#include "Button.h"

class Program
{
    sf::Font _font;
    sf::RenderWindow _win;
    std::vector<sf::Button *> _buttons;
    Stack _stack;
    void init();
    void update(sf::Event &e);
    void draw();
    void EventHandler(sf::Event &e);

public:
    Program();
    void begin();
};