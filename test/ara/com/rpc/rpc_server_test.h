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
            class RpcServerTest : public ara::com::someip::rpc::SocketRpcServer
            {
            private:
                // bool handleWithTrue(
                //     const std::vector<uint8_t> &rpcRequestPdu,
                //     std::vector<uint8_t> &rpcResponsePdu) const;

                // bool handleWithFalse(
                //     const std::vector<uint8_t> &rpcRequestPdu,
                //     std::vector<uint8_t> &rpcResponsePdu) const;
                // someip::rpc::SocketRpcServer *socketRpcServer;


            protected:

            public:
                RpcServerTest(AsyncBsdSocketLib::Poller *poller, std::string ipAddress, uint16_t port, uint8_t protocolVersion, uint8_t interfaceVersion);

                static void readMsg();

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
