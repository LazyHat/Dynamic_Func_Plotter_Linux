#include "Program.h"

using namespace sf;
using namespace std;

Program::Program()
{
    win = new RenderWindow(VideoMode(800, 500), "Plotter");
    stack = new Stack();
}
Program::~Program()
{
    delete win;
    delete stack;
}
void Program::update()
{
}
void Program::EventHandler(Event e)
{
    switch (e.type)
    {
    case Event::Closed:
        win->close();
        break;
    }
}
void Program::init()
{
}
void Program::draw()
{
    win->clear();
    win->display();
}
void Program::begin()
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