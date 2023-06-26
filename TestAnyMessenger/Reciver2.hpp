#pragma once
#include "Messages.hpp"
#include <AnyMessenger/Reciver.hpp>
#include <AnyMessenger/Messenger.hpp>

namespace TestAnyMessenger
{
    struct Reciver2 :
        public AnyMessenger::Reciver<Message2>
    {
    public:
        Reciver2(AnyMessenger::Messenger& messenger) : m_messenger{ messenger }
        {
            m_messenger.Register<Message2>(this);
        }

        ~Reciver2()
        {
            m_messenger.Unregister<Message2>(this);
        }

        void Recive(const std::shared_ptr<Message2> message) override
        {
            std::cout << "Reciver2 - Recived Message2 " << message->Value << std::endl;
        }

    private:
        AnyMessenger::Messenger& m_messenger;
    };
}