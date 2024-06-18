#include "pubsub_test.h"

int main() {
    using namespace ara::com::someip;

    pubsub::PubServerTest serverTest;
    serverTest.StartServer();

    serverTest.ServerGetState();

    sd::SomeIpSdMessage _message;

    serverTest.Subscribe();

    serverTest.checksucced(_message);

    serverTest.ServerGetState();

    serverTest.SendEventGroup({0x01, 0x02, 0x03, 0x04});

    serverTest.PublishToROS2({0x01, 0x02, 0x03, 0x04});

    return 0;
}