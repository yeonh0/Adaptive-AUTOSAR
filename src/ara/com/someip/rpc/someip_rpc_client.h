#ifndef SOMEIP_RPC_CLIENT_TEST_H
#define SOMEIP_RPC_CLIENT_TEST_H

#include <ostream>
#include <vector>
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

// Include SOMEIP RPC Client
#include "socket_rpc_client.h"

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            class SomeIpClient : public ara::com::someip::rpc::SocketRpcClient
            {
            private:

            protected:
                static AsyncBsdSocketLib::Poller defaultPoller;
                static const std::string defaultIpAddress;
                static const uint16_t defaultPort = 8080;
                static const uint8_t defaultProtocolVersion = 1;
                static const uint8_t defaultInterfaceVersion = 1;
                
            public:
                SomeIpClient(AsyncBsdSocketLib::Poller *poller, std::string ipAddress, uint16_t port, uint8_t protocolVersion, uint8_t interfaceVersion = 1);
                
                
                // RpcClient::Send -> Send SOME/IP RPC Msg
                void SendRpcMessage(uint16_t serviceId, uint16_t methodId, uint16_t clientId, const std::vector<uint8_t> &rpcPayload);
            };
        }
    }
}

#endif // SOMEIP_RPC_CLIENT_TEST_H