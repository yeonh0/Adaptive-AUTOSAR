#include "proxy.h"

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            void myProxy::handleResponse(const someip::SomeIpMessage &response) const
            {
                std::vector<uint8_t> rpcpayload = response.Payload();

                for (std::vector<uint8_t>::size_type i = 0; i < rpcpayload.size(); i++) {
                    std::cout << rpcpayload[i];
                }
                std::cout << std::endl;
            }

            const std::string myProxy::serverIpAddress = "172.24.125.198";
            const uint16_t myProxy::serverPort = 33333;
            const uint8_t myProxy::protocolVersion = 1;
            const uint8_t myProxy::interfaceVersion = 1;
            
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            myProxy::myProxy()
                : client(&poller,
                            serverIpAddress,
                            serverPort,
                            protocolVersion,
                            interfaceVersion)
            {
                // ros2 service client

                auto _SetSpeedCallback = std::bind(
                                &myProxy::handleResponse,
                                this,
                                std::placeholders::_1);

                client.SetHandler(serviceId, SetSpeed_methodId, _SetSpeedCallback);
            }

            void myProxy::SetSpeed(
                std::vector<uint8_t> rpcPayload,
                std::vector<uint8_t> rpcResponse
            )
            {
                // someip call service
                client.callMethodWithReply(serviceId, SetSpeed_methodId, clientId, rpcPayload);

                // ros2 call service
                
            }
        }
    }
}