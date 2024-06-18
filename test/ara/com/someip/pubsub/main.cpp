#include "someip_pubsub_test.h"

int main() {
    using namespace ara::com::someip;

    pubsub::SomeIpPubServerTest serverTest;
    serverTest.StartServer();

    serverTest.ServerGetState();

    sd::SomeIpSdMessage _message;

    serverTest.Subscribe();

    serverTest.checksucced(_message);

    serverTest.ServerGetState();

    return 0;
}