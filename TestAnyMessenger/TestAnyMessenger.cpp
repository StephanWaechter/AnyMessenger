// AnyQueue.cpp : Defines the entry point for the application.
//

#include "Reciver1.hpp"
#include "Reciver2.hpp"

using namespace std;
using namespace AnyMessenger;
using namespace TestAnyMessenger;

int main()
{
    Messenger messenger;
    auto reciver1 = messenger.create_reciver<Reciver1>();
    {
        auto reciver2 = messenger.create_reciver<Reciver2>();

        messenger.send<Message1>(1);
        messenger.send<Message2>("Test 1");
    }

    messenger.send<Message1>(2);
    messenger.send<Message2>("Test 2");

	return 0;
}
