#include "Program.h"

using namespace sf;

Program::Program()
{
    win.create(VideoMode(800, 500), "Plotter");
    _font.loadFromFile("Ubuntu-L.ttf");
}
void Program::update(Event &e)
{
}
void Program::EventHandler(Event &e)
{
    for (auto b : buttons)
    {
        b->Update(e, win);
    }
    switch (e.type)
    {
    case Event::Closed:
        win.close();
        break;
    }
}
void Program::init()
{
    win.setFramerateLimit(1 / 120);
    buttons.push_back(new Button(Vector2f(20, 20), Vector2f(50, 50), _font));
}
void Program::draw()
{
    win.clear();
    for (auto b : buttons)
    {
        win.draw(*b);
    }
    win.display();
}
void Program::begin()
{
    init();
    while (win.isOpen())
    {
        Event e;
        while (win.pollEvent(e))
            EventHandler(e);
        update(e);
        draw();
    }
}