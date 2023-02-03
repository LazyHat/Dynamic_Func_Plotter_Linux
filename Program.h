#pragma once
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "Stack.h"
#include "Button.h"
#include "TextBox.h"

class Program
{
    sf::Font _font;
    sf::RenderWindow _win;
    std::vector<sf::Text *> _signs;
    std::map<std::string, sf::Button *> _buttons;
    sf::TextBox _stackBox;
    Stack _stack;
    void init();
    void update(sf::Event &e);
    void draw();
    void EventHandler(sf::Event &e);

public:
    Program();
    void begin();
};