#pragma once
#include <string>

namespace TestAnyMessenger
{
    struct Message1
    {
        Message1(int value) : Value{ value } {}
        int Value;
    };

    struct Message2
    {
        Message2(std::string value) : Value{ value } {}
        std::string Value;
    };
}