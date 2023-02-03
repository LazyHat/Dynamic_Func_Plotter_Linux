#include "Plotter.h"

using namespace sf;
using namespace std;

Plotter::Plotter(const Stack stack)
{
    _win.create(VideoMode(800, 500), "Plotter");
    _stack = stack;
}

Plotter::~Plotter()
{
}

void Plotter::update()
{
}

void Plotter::EventHandler(const Event e)
{
    switch (e.type)
    {
    case Event::Closed:
        _win.close();
        break;
    }
}

void Plotter::init()
{
}

void Plotter::draw()
{
    _win.clear();
    _win.display();
}

void Plotter::begin()
{
    init();
    while (_win.isOpen())
    {
        Event e;
        while (_win.pollEvent(e))
        {
            EventHandler(e);
        }
        update();
        draw();
    }
}

bool Plotter::IsClosed() const { return !_win.isOpen(); }