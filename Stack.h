#pragma once

#include <string>
#include <list>
#include <map>
#include <cmath>

enum Commands
{
    ADD,
    MUL,
    DUP,
    SWAP,
    OVER,
    COS,
    SIN,
    TAN,
    CTAN,
    ACOS,
    ASIN,
    ATAN,
    ACTAN,
    SQRT,
    SUB,
    DIV
};

class Stack
{
    std::list<Commands> stackCommands;

public:
    Stack();
    bool IsCommand(std::string command) const;
    std::string GetListOfCommands() const;
    void Command(std::string command);
    float Execute(float x) const;
};