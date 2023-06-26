#pragma once
#include <AnyMessenger/Reciver.hpp>
#include <AnyMessenger/Messenger.hpp>
#include "Messages.hpp"
#include <iostream>

namespace TestAnyMessenger
{
    struct Reciver3 :
        public AnyMessenger::Reciver<Message1>,
        public AnyMessenger::Reciver<Message2>
    {
    public:
        Reciver3(AnyMessenger::Messenger& messenger) : m_messenger{ messenger }
        {
            m_messenger.Register<Message1>(this);
            m_messenger.Register<Message2>(this);
        }

        ~Reciver3()
        {
            m_messenger.Unregister<Message1>(this);
            m_messenger.Unregister<Message2>(this);
        }

        void Recive(const std::shared_ptr<Message1> message) override
        {
            sum += message->Value;
        }

        void Recive(const std::shared_ptr<Message2> message) override
        {
            
        }

        int sum{ 0 };

    private:
        AnyMessenger::Messenger& m_messenger;
    };
}