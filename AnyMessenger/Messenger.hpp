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
            send<MessageType>(message);
        }

        template<class MessageType>
        void send(const std::shared_ptr<MessageType> message)
        {
            auto& recipients = getRecipient<MessageType>();
            for (auto& recipient : recipients)
            {
                recipient->Recive(message);
            }
        }

        template<class MessageType>
        void Register(Reciver<MessageType>* reciver)
        {
            auto& recipients = getRecipient<MessageType>();
            recipients.push_back(reciver);
        }

        template<class MessageType>
        void Unregister(Reciver<MessageType>* reciver)
        {
            auto& recipients = getRecipient<MessageType>();
            auto itr = std::remove_if(
                recipients.begin(),
                recipients.end(),
                [reciver](auto const& recipient)
                {
                    return reciver == recipient;
                }
            );
            recipients.erase(itr);
        }

    private:
        template<class MessageType>
        std::vector<Reciver<MessageType>*>& getRecipient()
        {
            static std::vector<Reciver<MessageType>*> recipient;
            return recipient;
        }
    };
}