#include "pubsub_test.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace pubsub
            {             
                // Static member initialization
                const uint16_t PubServerTest::cCounter = 0;  
                const uint16_t PubServerTest::cServiceId = 1;
                const uint16_t PubServerTest::cInstanceId = 1;
                const uint8_t PubServerTest::cMajorVersion = 1;
                const uint16_t PubServerTest::cEventgroupId = 0;
                const uint16_t PubServerTest::cPort = 10001;
                const int PubServerTest::cWaitingDuration = 100;

                // Constructor definition
                PubServerTest::PubServerTest() 
                    : Server(&mNetworkLayer,
                             cServiceId,
                             cInstanceId,
                             cMajorVersion,
                             cEventgroupId,
                             helper::Ipv4Address(224, 0, 0, 0),
                             cPort), 
                      Client(&mNetworkLayer, cCounter)
                {
                    ros2Server = std::make_shared<ROS2PubSubServer>();  // ROS2PubSubServer 초기화
                }

            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Server
            ////////////////////////////////////////////////////////////////////////////////////////////////////

                // Member function definitions
                void PubServerTest::StartServer()
                {
                    Server.Start();
                    std::cout << "ServiceId: " << cServiceId << " Instance id: " << cInstanceId << std::endl;
                }

                // Read Server Subscribe State
                void PubServerTest::ServerGetState()
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

                // Send Message To All Subscriber
                void PubServerTest::SendEventGroup(const std::vector<uint8_t> payload)
                {
                    const std::vector<uint8_t> cRpcPayload = payload;

                    SomeIpPubsubMessage message(
                        1,
                        2,
                        1,
                        1,
                        1,
                        cRpcPayload);

                    Server.SendMessageToEventGroup(message);
                }

                // Publish to ROS2
                void PubServerTest::PublishToROS2(const std::vector<uint8_t>& payload)
                {
                    ros2Server->PublishMessage(payload);
                }


            ////////////////////////////////////////////////////////////////////////////////////////////////////
            // Client
            ////////////////////////////////////////////////////////////////////////////////////////////////////
                void PubServerTest::Subscribe()
                {
                    Client.Subscribe(cServiceId, cInstanceId, cMajorVersion, cEventgroupId);
                }

                void PubServerTest::checksucced(sd::SomeIpSdMessage &msg)
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
