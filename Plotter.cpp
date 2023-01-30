#include "Plotter.h"

using namespace sf;
using namespace std;
Plotter::Plotter()
{
    win = new RenderWindow(VideoMode(800, 500), "Plotter");
}
void Plotter::update()
{
}
void Plotter::EventHandler(Event e)
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