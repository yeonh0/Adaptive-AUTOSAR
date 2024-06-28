#include "pubsub_test.h"

int main() {
    using namespace ara::com;

    pubsub::PubServerTest serverTest;
    serverTest.StartServer();

    serverTest.ServerGetState();

    someip::sd::SomeIpSdMessage _message;

    serverTest.Subscribe();

    serverTest.checksucced(_message);

    serverTest.ServerGetState();

    while(1) {
        serverTest.SendEventGroup({0x01, 0x02, 0x03, 0x04});
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}