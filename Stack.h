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
    std::list<std::string> GetStackListStr() const;
    std::map<std::string, Commands> GetMapOfCommands() const;
    int GetCountOfUnaryCommands() const;
    int GetCountOfBinaryCommands() const;
    int GetCountOfStackCommands() const;
    std::string GetCommandStr(Commands command) const;
    Commands GetUnaryCommand(int index) const;
    Commands GetBinaryCommand(int index) const;
    Commands GetStackCommand(int index) const;
    void Command(std::string command);
    float Execute(float x) const;
};