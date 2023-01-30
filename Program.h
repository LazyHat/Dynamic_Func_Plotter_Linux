#pragma once
#include "BaseWindow.h"

class Program : BaseWindow
{
    Stack *stack = nullptr;
    void init();
    void update();
    void draw();
    void EventHandler(sf::Event e);

public:
    Program();
    ~Program();
    void begin();
};