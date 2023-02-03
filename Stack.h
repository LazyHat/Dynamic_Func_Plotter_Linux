#pragma once

#include <string>
#include <vector>
#include <list>
#include <map>
#include <cmath>

enum Commands
{
    DUP = 0,
    SWAP,
    OVER,
    COS = 10,
    SIN,
    TAN,
    CTAN,
    ACOS,
    ASIN,
    ATAN,
    ACTAN,
    SQRT,
    SUM = 20,
    SUB,
    MUL,
    DIV
};

class Stack
{
    std::list<Commands> stackCommands;

public:
    Stack();
    bool IsCommand(std::string command) const;
    std::string GetStrCommands() const;
    std::map<std::string, Commands> GetMapOfCommands() const;
    size_t GetCountOfCommands() const;
    void Command(std::string command);
    float Execute(float x) const;
};