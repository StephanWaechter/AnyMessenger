#pragma once
#include <AnyMessenger/Reciver.hpp>
#include <AnyMessenger/Messenger.hpp>
#include "Messages.hpp"
#include <iostream>

namespace TestAnyMessenger
{
    struct Reciver1 :
        public AnyMessenger::Reciver<Message1>,
        public AnyMessenger::Reciver<Message2>
    {
    public:
        Reciver1(AnyMessenger::Messenger& messenger) : m_messenger{ messenger }
        {
            m_messenger.Register<Message1>(this);
            m_messenger.Register<Message2>(this);
        }

        ~Reciver1()
        {
            m_messenger.Unregister<Message1>(this);
            m_messenger.Unregister<Message2>(this);
        }

        void Recive(const std::shared_ptr<Message1> message) override
        {
            std::cout << "Reciver1 - Recived Message1 " << message->Value << std::endl;
        }

        void Recive(const std::shared_ptr<Message2> message) override
        {
            std::cout << "Reciver1 - Recived Message2 " << message->Value << std::endl;
        }

    private:
        AnyMessenger::Messenger& m_messenger;
    };
}