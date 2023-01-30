#pragma once
#include "BaseWindow.h"

class Plotter : BaseWindow
{
    const Stack *stack = nullptr;
    void init();
    void update();
    void draw();
    void EventHandler(const sf::Event e);

public:
    Plotter(const Stack *_stack);
    ~Plotter();
    void begin();
};