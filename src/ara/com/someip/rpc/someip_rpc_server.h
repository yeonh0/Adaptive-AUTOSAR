#ifndef RPC_SERVER_TEST_H
#define RPC_SERVER_TEST_H

#include <ostream>
#include <vector>
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

// Include SOMEIP RPC Server
#include "socket_rpc_server.h"

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            class SomeIpRpcServer : public ara::com::someip::rpc::SocketRpcServer
            {
            private:

            protected:

            public:
                SomeIpRpcServer(AsyncBsdSocketLib::Poller *poller, std::string ipAddress, uint16_t port, uint8_t protocolVersion, uint8_t interfaceVersion);

                // bool RPCTryInvokeHandler(const std::vector<uint8_t> &requestPayload, std::vector<uint8_t> &responsePayload) const
                // {
                //     return TryInvokeHandler(requestPayload, responsePayload);
                // }

                void onReceive();
            };
        }
    }
}

#endif // RPC_SERVER_TEST_H
