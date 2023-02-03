#include "Stack.h"
#include <exception>

std::map<std::string, Commands> commandsMap = {
    {"DUP", Commands::DUP},
    {"SWAP", Commands::SWAP},
    {"OVER", Commands::OVER},
    {"COS", Commands::COS},
    {"SIN", Commands::SIN},
    {"TAN", Commands::TAN},
    {"CTAN", Commands::CTAN},
    {"ASIN", Commands::ASIN},
    {"ACOS", Commands::ACOS},
    {"ATAN", Commands::ATAN},
    {"ACTAN", Commands::ACTAN},
    {"SQRT", Commands::SQRT},
    {"SUM", Commands::SUM},
    {"SUB", Commands::SUB},
    {"MUL", Commands::MUL},
    {"DIV", Commands::DIV}};

Stack::Stack() {}

void Stack::Command(std::string command)
{
    if (!IsCommand(command))
        throw std::exception();
    stackCommands.push_back(commandsMap[command]);
}

bool Stack::IsCommand(std::string command) const
{
    return commandsMap.find(command) != commandsMap.end();
}

std::string Stack::GetStrCommands() const
{
    std::string result;

    result += commandsMap.begin()->first;

    for (auto label = ++commandsMap.begin(); label != commandsMap.end(); label++)
    {
        result += "," + label->first;
    }
    return result;
}

std::map<std::string, Commands> Stack::GetMapOfCommands() const
{
    return commandsMap;
}

int Stack::GetCountOfUnaryCommands() const
{
    int result = 0;
    for (auto cmd : commandsMap)
    {
        if (cmd.second >= 10 && cmd.second < 20)
            result++;
    }
    return result;
}
int Stack::GetCountOfBinaryCommands() const
{
    int result = 0;
    for (auto cmd : commandsMap)
    {
        if (cmd.second >= 20)
            result++;
    }
    return result;
}
int Stack::GetCountOfStackCommands() const
{
    int result = 0;
    for (auto cmd : commandsMap)
    {
        if (cmd.second < 10)
            result++;
    }
    return result;
}

Commands Stack::GetUnaryCommand(int index) const
{
    return static_cast<Commands>(index + 10);
}
Commands Stack::GetBinaryCommand(int index) const
{
    return static_cast<Commands>(index + 20);
}
Commands Stack::GetStackCommand(int index) const
{
    return static_cast<Commands>(index);
}

std::string
Stack::GetCommandStr(Commands command) const
{
    for (auto i : commandsMap)
        if (i.second == command)
            return i.first;
}

float Stack::Execute(float x) const
{
    std::list<float> st;

    st.push_back(x);

    for (auto &&i : stackCommands)
    {
        switch (i)
        {

        case Commands::SUM:
            if (st.size() > 1)
            {
                *(--st.end()) += *(-- --st.end());
                st.erase(-- --st.end());
            }
            break;

        case Commands::MUL:
            if (st.size() > 1)
            {
                *(--st.end()) *= *(-- --st.end());
                st.erase(-- --st.end());
            }
            break;

        case Commands::DUP:
            st.push_back(*(--st.end()));
            break;

        case Commands::SWAP:
            if (st.size() > 1)
            {
                float temp;
                temp = *(--st.end());
                *(--st.end()) = *(-- --st.end());
                *(-- --st.end()) = temp;
            }
            break;

        case Commands::OVER:
            st.push_back(*(-- --st.end()));
            break;

        case Commands::COS:
            *(--st.end()) = cos(*(--st.end()));
            break;

        case Commands::SIN:
            *(--st.end()) = sin(*(--st.end()));
            break;

        case Commands::TAN:
            *(--st.end()) = tan(*(--st.end()));
            break;

        case Commands::CTAN:
            *(--st.end()) = 1 / tan(*(--st.end()));
            break;

        case Commands::ASIN:
            *(--st.end()) = asin(*(--st.end()));
            break;

        case Commands::ACOS:
            *(--st.end()) = acos(*(--st.end()));
            break;

        case Commands::ATAN:
            *(--st.end()) = atan(*(--st.end()));
            break;

        case Commands::ACTAN:
            *(--st.end()) = atan(*(--st.end())) - M_PI / 2;
            break;

        case Commands::SQRT:
            *(--st.end()) = sqrt(*(--st.end()));
            break;

        case Commands::SUB:
            if (st.size() > 1)
            {
                *(--st.end()) -= *(-- --st.end());
                st.erase(-- --st.end());
            }
            break;

        case Commands::DIV:
            if (st.size() > 1)
            {
                *(--st.end()) /= *(-- --st.end());
                st.erase(-- --st.end());
            }
            break;
        }
    }
    return *(--st.end());
}