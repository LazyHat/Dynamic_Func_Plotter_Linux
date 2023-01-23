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
    SQRT,
    SUB,
    DIV
};

std::map<std::string, Commands> commands = {
    {"ADD", Commands::ADD},
    {"DUP", Commands::DUP},
    {"SWAP", Commands::SWAP},
    {"OVER", Commands::OVER},
    {"MUL", Commands::MUL},
    {"COS", Commands::COS},
    {"SIN", Commands::SIN},
    {"SQRT", Commands::SQRT},
    {"SUB", Commands::SUB},
    {"DIV", Commands::DIV}};

class Stack
{
    std::list<Commands> cms;

public:
    Stack();
    void Command(Commands com);
    float Execute(float x);
};