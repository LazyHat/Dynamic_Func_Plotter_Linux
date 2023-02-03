#include "Stack.h"
#include <exception>
#include <algorithm>
#include <cctype>

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

std::list<std::string> Stack::GetStackListStr() const
{
    std::vector<std::string> res;
    std::string x = "x";
    res.push_back(x);
    for (auto cmd : stackCommands)
    {
        switch (cmd)
        {
        case DUP:
            res.insert(res.begin() + 1, res[0]);
            break;

        case SWAP:
        {
            if (res.size() > 1)
            {
                std::string var = res[0];
                res[0] = res[1];
                res[1] = var;
            }
        }
        break;

        case OVER:
            if (res.size() > 2)
                res.insert(res.begin(), res[1]);
            break;

        case SUM:
            if (res.size() > 1)
                if (res[0] == res[1])
                    res[0] = "2*" + res[0];
                else
                    res[0] = res[0] + "+(" + res[1] + ")";
            res.erase(res.begin() + 1);
            break;

        case SUB:
            if (res.size() > 1)
                if (res[0] == res[1])
                    res[0] = "0";
                else
                    res[0] = res[0] + "-(" + res[1] + ")";
            res.erase(res.begin() + 1);
            break;

        case MUL:
            if (res.size() > 1)
                if (res[0] == res[1])
                    res[0] = "(" + res[0] + ")^2";
                else
                    res[0] = res[0] + "*(" + res[1] + ")";
            res.erase(res.begin() + 1);
            break;

        case DIV:
            if (res.size() > 1)
                if (res[0] == res[1])
                    res[0] = "1";
                else
                    res[0] = res[0] + "/(" + res[1] + ")";
            res.erase(res.begin() + 1);
            break;

        default:
            if (cmd >= 10 && cmd <= 20)
            {
                std::string scmd = GetCommandStr(cmd);
                for (auto &&c : scmd)
                    if (c <= 'Z' && c >= 'A')
                        c = c - 'A' + 'a';
                res[0] = scmd + "(" + res[0] + ")";
            }
            else
                throw std::exception();
        }
    }
    std::list<std::string> result;
    for (auto s : res)
    {
        result.push_back(s);
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
    throw std::exception();
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
        default:
            throw std::exception();
        }
    }
    return *(--st.end());
}