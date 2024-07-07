#include "proxy.h"

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            const std::string myProxy::serverIpAddress = "172.24.125.198";
            const uint16_t myProxy::serverPort = 33333;
            const uint8_t myProxy::protocolVersion = 1;
            const uint8_t myProxy::interfaceVersion = 1;

            myProxy::myProxy()
                : client(&poller,
                            serverIpAddress,
                            serverPort,
                            protocolVersion,
                            interfaceVersion)
            {
                // ros2 service client
            }

            void myProxy::CallService(
                uint16_t serviceId,
                uint16_t methodId,
                uint16_t clientId,
                std::vector<uint8_t> rpcPayload
            )
            {
                client.SendRpcMessage(serviceId, methodId, clientId, rpcPayload);
                // ros2 call service
            }
        }
    }
}