#pragma once
#include "BaseWindow.h"

class Program : BaseWindow
{
    void init();
    void update();
    void draw();
    void EventHandler(sf::Event e);

public:
    Program();
    void begin();
};