#include "Program.h"

using namespace sf;

Program::Program()
{
    _win.create(VideoMode(800, 500), "Plotter");
    _font.loadFromFile("Ubuntu-L.ttf");
}
void Program::update(Event &e)
{
}
void Program::EventHandler(Event &e)
{
    for (auto b : _buttons)
    {
        b->Update(e, _win);
    }
    switch (e.type)
    {
    case Event::Closed:
        _win.close();
        break;
    }
}
void Program::init()
{
    _win.setFramerateLimit(1 / 120);
    for (int h = 0; h < _stack.GetCountOfCommands() / 5; h++)
        for (int w = 0; w < 5 && w * h < _stack.GetCountOfCommands(); w++)
            _buttons.push_back(new Button(Vector2f(20 + w * 60, 20 + h * 40), Vector2f(50, 30), _font, _stack.GetVecCommands()[w * h]));
}
void Program::draw()
{
    _win.clear(Color(180, 180, 180));
    for (auto b : _buttons)
    {
        _win.draw(*b);
    }
    _win.display();
}
void Program::begin()
{
    init();
    while (_win.isOpen())
    {
        Event e;
        while (_win.pollEvent(e))
            EventHandler(e);
        update(e);
        draw();
    }
}