#ifndef RPC_SERVER_TEST_H
#define RPC_SERVER_TEST_H

#include <ostream>
#include <vector>
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

// Include SOMEIP RPC Server
#include "../../../../src/ara/com/someip/rpc/socket_rpc_server.h"

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            class RpcServerTest
            {
            private:
                // bool handleWithTrue(
                //     const std::vector<uint8_t> &rpcRequestPdu,
                //     std::vector<uint8_t> &rpcResponsePdu) const;

                // bool handleWithFalse(
                //     const std::vector<uint8_t> &rpcRequestPdu,
                //     std::vector<uint8_t> &rpcResponsePdu) const;


            protected:
                static AsyncBsdSocketLib::Poller *poller;
                static const std::string ipAddress;
                static const uint16_t port;
                static const uint8_t protocolVersion;
                static const uint8_t interfaceVersion;

                someip::rpc::SocketRpcServer someipServer;


            public:
                RpcServerTest();
                static void setPoller(AsyncBsdSocketLib::Poller* p);
                static void onAccept();

                //void ServerGetState();
                //void RegisterCallback(const std::vector<uint8_t> payload);

                // bool RPCTryInvokeHandler(const std::vector<uint8_t> &requestPayload, std::vector<uint8_t> &responsePayload) const
                // {
                //     return TryInvokeHandler(requestPayload, responsePayload);
                // }

                uint32_t GetMessageId(uint16_t serviceId, uint16_t methodId);
            };
        }
    }
}

#endif // RPC_SERVER_TEST_H
