
#include "someip_pubsub_test.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace pubsub
            {             
                // Static member initialization
                const uint16_t SomeIpPubServerTest::cCounter = 0;  
                const uint16_t SomeIpPubServerTest::cServiceId = 1;
                const uint16_t SomeIpPubServerTest::cInstanceId = 1;
                const uint8_t SomeIpPubServerTest::cMajorVersion = 1;
                const uint16_t SomeIpPubServerTest::cEventgroupId = 0;
                const uint16_t SomeIpPubServerTest::cPort = 10001;
                const int SomeIpPubServerTest::cWaitingDuration = 100;

                // Constructor definition
                SomeIpPubServerTest::SomeIpPubServerTest() 
                    : Server(&mNetworkLayer,
                             cServiceId,
                             cInstanceId,
                             cMajorVersion,
                             cEventgroupId,
                             helper::Ipv4Address(224, 0, 0, 0),
                             cPort), 
                      Client(&mNetworkLayer, cCounter)
                {
                }

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Server
            ////////////////////////////////////////////////////////////////////////////////////////////////////

                // Member function definitions
                void SomeIpPubServerTest::StartServer()
                {
                    Server.Start();
                    std::cout << "ServiceId: " << cServiceId << " Instance id: " << cInstanceId << std::endl;
                }

                // Read Server Subscribe State
                void SomeIpPubServerTest::ServerGetState()
                {
                    helper::PubSubState serverstate = Server.GetState();

                    switch(serverstate) {
                        case helper::PubSubState::ServiceDown:
                            std::cout << "Service server is down" << std::endl;
                            break;
                        case helper::PubSubState::NotSubscribed:
                            std::cout << "Service server is up, but there is no subscriber" << std::endl;
                            break;
                        case helper::PubSubState::Subscribed:
                            std::cout << "Service server is up, and there is at least a subscriber" << std::endl;
                            break;
                        default:
                            std::cout << "Unknown state" << std::endl;
                            break;
                    }
                }

                // Read Message From Client



            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Client
            ////////////////////////////////////////////////////////////////////////////////////////////////////
                void SomeIpPubServerTest::Subscribe()
                {
                    Client.Subscribe(cServiceId, cInstanceId, cMajorVersion, cEventgroupId);
                }

                void SomeIpPubServerTest::checksucced(sd::SomeIpSdMessage &msg)
                {
                    bool _succeed = Client.TryGetProcessedSubscription(cWaitingDuration, msg);
                    if (_succeed) 
                        std::cout << "successfully subscribe" << std::endl;
                    else  
                        std::cout << "subscribe failed" << std::endl;
                }
            }
        }
    }
}
