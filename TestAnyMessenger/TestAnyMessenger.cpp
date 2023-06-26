// AnyQueue.cpp : Defines the entry point for the application.
//

#include "Reciver1.hpp"
#include "Reciver2.hpp"
#include "Reciver3.hpp"

#include <chrono>

using namespace std;
using namespace AnyMessenger;
using namespace TestAnyMessenger;
using ms = std::chrono::milliseconds;

void test()
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
}

void profile()
{
    auto start = std::chrono::system_clock::now();
    Messenger messenger;
    auto reciver = messenger.create_reciver<Reciver3>();
    for (int k = 0; k < 1000000; k++)
    {
        messenger.send<Message1>(k);
    }
    auto end = std::chrono::system_clock::now();
    std::cout << "Sum " << reciver->sum << std::endl;
    std::cout << "Runtime: " << std::chrono::duration_cast<ms>(end - start) << std::endl;
}

int main()
{
    profile();
    return 0;
}