#include "Stack.h"

Stack::Stack() {}

void Stack::Command(Commands com)
{
    cms.push_back(com);
}

float Stack::Execute(float x)
{
    std::list<float> st;

    st.push_back(x);

    for (auto &&i : cms)
    {
        switch (i)
        {

        case Commands::ADD:
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