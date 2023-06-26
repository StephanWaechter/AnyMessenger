#pragma once
#include <memory>

namespace AnyMessenger
{
    template<class MessageType>
    struct Reciver
    {
        virtual void Recive(const std::shared_ptr<MessageType> message) = 0;
    };
}