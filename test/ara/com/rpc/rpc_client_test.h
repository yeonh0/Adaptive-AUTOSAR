#ifndef RPC_CLIENT_TEST_H
#define RPC_CLIENT_TEST_H

#include <ostream>
#include <vector>
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

// Include SOMEIP RPC Client
#include "../../../../src/ara/com/someip/rpc/socket_rpc_client.h"

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            class RpcClientTest
            {
            private:

            protected:
                static AsyncBsdSocketLib::Poller *poller;
                static const std::string ipAddress;
                static const uint16_t port;
                static const uint8_t protocolVersion;
                static const uint8_t interfaceVersion;
                
                someip::rpc::SocketRpcClient someipClient;

            public:
                RpcClientTest();
                static void setPoller(AsyncBsdSocketLib::Poller* p);
            };
        }
    }
}

#endif // RPC_CLIENT_TEST_H