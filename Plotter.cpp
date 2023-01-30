#include "Plotter.h"

using namespace sf;
using namespace std;
Plotter::Plotter(const Stack *_stack)
{
    win = new RenderWindow(VideoMode(800, 500), "Plotter");
    stack = _stack;
}
Plotter::~Plotter()
{
    delete win;
    win = nullptr;
    delete stack;
    stack = nullptr;
}
void Plotter::update()
{
}
void Plotter::EventHandler(const Event e)
{
    switch (e.type)
    {
    case Event::Closed:
        win->close();
        break;
    }
}
void Plotter::init()
{
}
void Plotter::draw()
{
    win->clear();
    win->display();
}
void Plotter::begin()
{
    init();
    while (win->isOpen())
    {
        Event e;
        while (win->pollEvent(e))
        {
            EventHandler(e);
        }
        update();
        draw();
    }
}