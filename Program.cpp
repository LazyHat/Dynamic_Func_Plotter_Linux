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
        b.second->Update(e, _win);
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
    for (int i = 0; i < 4; i++)
        _signs.push_back(new Text("", _font, 20));
    _signs[0]->setPosition(20, 255);
    _signs[0]->setString("Unary Commands:");
    for (int h = 0; h <= _stack.GetCountOfUnaryCommands() / 5; h++)
        for (int w = 0; w < 5 && w + h * 5 < _stack.GetCountOfUnaryCommands(); w++)
        {
            std::string cmd = _stack.GetCommandStr(_stack.GetUnaryCommand(w + h * 5));
            _buttons[cmd] = new Button(Vector2f(20 + w * 70, 300 + h * 40), Vector2f(60, 30), _font, cmd);
        }
    _signs[1]->setPosition(20, 400);
    _signs[1]->setString("Binary Commands:");
    for (int w = 0; w < _stack.GetCountOfBinaryCommands(); w++)
    {
        std::string cmd = _stack.GetCommandStr(_stack.GetBinaryCommand(w));
        _buttons[cmd] = new Button(Vector2f(20 + w * 70, 445), Vector2f(60, 30), _font, cmd);
    }
    _signs[2]->setPosition(350, 400);
    _signs[2]->setString("Stack Commands:");
    for (int w = 0; w < _stack.GetCountOfStackCommands(); w++)
    {
        std::string cmd = _stack.GetCommandStr(_stack.GetStackCommand(w));
        _buttons[cmd] = new Button(Vector2f(350 + w * 70, 445), Vector2f(60, 30), _font, cmd);
    }
    _signs[3]->setPosition(600, 20);
    _signs[3]->setString("Stack");
}
void Program::draw()
{
    _win.clear(Color(180, 180, 180));
    for (auto l : _signs)
        _win.draw(*l);
    for (auto b : _buttons)
        _win.draw(*(b.second));
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