#pragma once
#include "BaseWindow.h"

class Plotter : BaseWindow
{
    void init();
    void update();
    void draw();
    void EventHandler(sf::Event e);

public:
    Plotter();
    void begin();
};