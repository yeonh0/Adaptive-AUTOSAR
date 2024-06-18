#ifndef PUBSUB_TEST_H
#define PUBSUB_TEST_H

#include <ostream>
#include <vector>
#include <iostream>

#include "../../../../../src/ara/com/someip/pubsub/someip_pubsub_server.h"
#include "../../../../../src/ara/com/someip/pubsub/someip_pubsub_client.h"
#include "../../../../../src/ara/com/someip/pubsub/someip_pubsub_message.h"

#include "../../helper/mockup_network_layer.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace pubsub
            {             
                class PubServerTest
                {
                private:  
                    static const uint16_t cCounter;  
                    helper::MockupNetworkLayer<sd::SomeIpSdMessage> mNetworkLayer;

                protected:
                    static const uint16_t cServiceId;
                    static const uint16_t cInstanceId;
                    static const uint8_t cMajorVersion;
                    static const uint16_t cEventgroupId;
                    static const uint16_t cPort;
                    static const int cWaitingDuration;

                    SomeIpPubSubServer Server;
                    SomeIpPubSubClient Client;

                public:
                    PubServerTest();

                    void StartServer();
                    void ServerGetState();
                    void SendEventGroup(const std::vector<uint8_t> payload);

                    void Subscribe();
                    void checksucced(sd::SomeIpSdMessage &msg);
                };
            }
        }
    }
}
#endif // SOMEIP_PUBSUB_TEST_H