#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Stack.h"
#include "Button.h"

class Program
{
    sf::Font _font;
    sf::RenderWindow win;
    std::vector<sf::Button *> buttons;
    Stack stack;
    void init();
    void update(sf::Event &e);
    void draw();
    void EventHandler(sf::Event &e);

public:
    Program();
    void begin();
};