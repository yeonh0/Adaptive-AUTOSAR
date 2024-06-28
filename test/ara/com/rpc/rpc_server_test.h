#ifndef RPC_SERVER_TEST_H
#define RPC_SERVER_TEST_H

#include "../../../../../src/ara/com/someip/rpc/rpc_server.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace rpc
            {
                class RpcServerTest : public RpcServer
                {
                private:
                    bool handleWithTrue(
                        const std::vector<uint8_t> &rpcRequestPdu,
                        std::vector<uint8_t> &rpcResponsePdu) const;

                    bool handleWithFalse(
                        const std::vector<uint8_t> &rpcRequestPdu,
                        std::vector<uint8_t> &rpcResponsePdu) const;

                protected:
                    const uint16_t cServiceId{1};
                    const uint16_t cTrueMethodId{1};
                    const uint16_t cFalseMethodId{2};
                    const uint16_t cClientId{2};
                    const uint16_t cSessionId{1};
                    const std::vector<uint8_t> cRpcPayload;
                    static const uint8_t cProtocolVersion{1};
                    static const uint8_t cInterfaceVersion{1};

                public:
                    RpcServerTest();

                    bool RPCTryInvokeHandler(const std::vector<uint8_t> &requestPayload, std::vector<uint8_t> &responsePayload) const
                    {
                        return TryInvokeHandler(requestPayload, responsePayload);
                    }

                    uint32_t GetMessageId(uint16_t serviceId, uint16_t methodId);
                };
            }
        }
    }
}

#endif // RPC_SERVER_TEST_H
