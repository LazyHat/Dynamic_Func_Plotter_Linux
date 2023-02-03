#pragma once
#include <SFML/Graphics.hpp>
#include "Stack.h"

class Plotter
{
    sf::RenderWindow _win;
    Stack _stack;
    void init();
    void update();
    void draw();
    void EventHandler(const sf::Event e);

public:
    Plotter(const Stack _stack);
    ~Plotter();
    void begin();
    bool IsClosed() const;
};