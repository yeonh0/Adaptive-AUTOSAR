#ifndef RPC_CLIENT_TEST_H
#define RPC_CLIENT_TEST_H

#include "../../../../../src/ara/com/someip/rpc/rpc_client.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace rpc
            {
                class RpcClientTest : public RpcClient
                {
                private:
                    void handleResponse(const SomeIpMessage &response) const;

                protected:
                    const uint16_t cServiceId{1};
                    const uint16_t cMethodId{1};
                    static const uint8_t cProtocolVersion{1};
                    static const uint8_t cInterfaceVersion{1};
                    mutable uint16_t LastSessionId;

                public:
                    RpcClientTest();

                    void Send(const std::vector<uint8_t> &payload) override;
            
                public:
                    using RpcClient::Send;
                };
            }
        }
    }
}

#endif // RPC_CLIENT_TEST_H