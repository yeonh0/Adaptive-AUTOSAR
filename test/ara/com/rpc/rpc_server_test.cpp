#include "rpc_server_test.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace rpc
            {
                RpcServerTest::RpcServerTest() : RpcServer(cProtocolVersion, cInterfaceVersion)
                {
                    auto _handleWithTrue{
                        std::bind(
                            &RpcServerTest::handleWithTrue,
                            this,
                            std::placeholders::_1,
                            std::placeholders::_2)};
                    SetHandler(cServiceId, cTrueMethodId, _handleWithTrue);

                    auto _handleWithFalse{
                        std::bind(
                            &RpcServerTest::handleWithFalse,
                            this,
                            std::placeholders::_1,
                            std::placeholders::_2)};
                    SetHandler(cServiceId, cFalseMethodId, _handleWithFalse);
                }

                uint32_t RpcServerTest::GetMessageId(uint16_t serviceId, uint16_t methodId)
                {
                    auto _result{static_cast<uint32_t>(serviceId << 16)};
                    _result |= methodId;

                    return _result;
                }

                bool RpcServerTest::handleWithTrue(
                    const std::vector<uint8_t> &rpcRequestPdu,
                    std::vector<uint8_t> &rpcResponsePdu) const
                {
                    return true;
                }

                bool RpcServerTest::handleWithFalse(
                    const std::vector<uint8_t> &rpcRequestPdu,
                    std::vector<uint8_t> &rpcResponsePdu) const
                {
                    return false;
                }
            }
        }
    }
}