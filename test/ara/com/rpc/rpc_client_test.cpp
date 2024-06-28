#include "rpc_client_test.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace rpc
            {
                RpcClientTest::RpcClientTest() : RpcClient(cProtocolVersion, cInterfaceVersion),
                                                 LastSessionId{0}
                {
                    auto _handleResponse{
                        std::bind(
                            &RpcClientTest::handleResponse,
                            this,
                            std::placeholders::_1)};
                    SetHandler(cServiceId, cMethodId, _handleResponse);
                }

                void RpcClientTest::handleResponse(const SomeIpMessage &response) const
                {
                    LastSessionId = response.SessionId();
                }

                void RpcClientTest::Send(const std::vector<uint8_t> &payload)
                {
                    // Short circuit the send
                    InvokeHandler(payload);
                }

                const uint8_t RpcClientTest::cProtocolVersion;
                const uint8_t RpcClientTest::cInterfaceVersion;
            }
        }
    }
}
