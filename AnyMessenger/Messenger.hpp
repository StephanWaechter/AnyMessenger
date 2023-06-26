#pragma once
#include <memory>
#include <vector>
#include <map>
#include <any>

namespace AnyMessenger
{
    class Messenger
    {
    public:
        template<class ReciverType>
        std::shared_ptr<ReciverType> create_reciver()
        {
            return std::make_shared<ReciverType>(*this);
        }

        template<class MessageType, class... _ArgTypes>
        void send(_ArgTypes&&... _Args)
        {
            auto message = std::make_shared<MessageType>(
                std::forward<_ArgTypes>(_Args)...
            );
            auto id = typeid(MessageType).hash_code();
            auto& recipients = m_recipients[id];
            for (auto& any : recipients)
            {
                auto recipient = std::any_cast<Reciver<MessageType>*>(any);
                recipient->Recive(message);
            }
        }

        template<class MessageType>
        void send(const std::shared_ptr<MessageType> message)
        {
            auto id = typeid(MessageType).hash_code();
            auto& recipients = m_recipients[id];
            for (auto& any : recipients)
            {
                auto recipient = std::any_cast<Reciver<MessageType>*>(any);
                recipient->Recive(message);
            }
        }

        template<class MessageType>
        void Register(Reciver<MessageType>* reciver)
        {
            auto id = typeid(MessageType).hash_code();
            m_recipients[id].push_back(reciver);
        }

        template<class MessageType>
        void Unregister(Reciver<MessageType>* reciver)
        {
            auto id = typeid(MessageType).hash_code();
            auto itr = std::remove_if(
                m_recipients[id].begin(),
                m_recipients[id].end(),
                [reciver](auto const& element)
                {
                    auto recipient = std::any_cast<Reciver<MessageType>*>(element);
            return reciver == recipient;
                }
            );
            m_recipients[id].erase(itr);
        }

    private:
        std::map<int, std::vector<std::any>> m_recipients;
    };
}