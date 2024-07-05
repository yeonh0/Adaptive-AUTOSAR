#include "rpc_server_test.h"

using namespace std;

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            AsyncBsdSocketLib::Poller* RpcServerTest::poller = nullptr;
            const std::string RpcServerTest::ipAddress = "0.0.0.0";
            const uint16_t RpcServerTest::port{1234};
            const uint8_t RpcServerTest::protocolVersion{1};
            const uint8_t RpcServerTest::interfaceVersion{1};

            RpcServerTest::RpcServerTest()
                : someipServer(poller, ipAddress, port, protocolVersion, interfaceVersion)
            {
                cout << "someip rpc server start" << endl;
            }

            void RpcServerTest::setPoller(AsyncBsdSocketLib::Poller* p) {
                poller = p;
            }

            void RpcServerTest::onAccept()
            {
                cout << "start to accept clients" << endl;
            }

            uint32_t RpcServerTest::GetMessageId(uint16_t serviceId, uint16_t methodId)
            {
                
                return 0;
            }
        }


        // namespace someip
        // {
        //     namespace rpc
        //     {
        //         RpcServerTest::RpcServerTest() : RpcServer(cProtocolVersion, cInterfaceVersion)
        //         {
        //             auto _handleWithTrue{
        //                 std::bind(
        //                     &RpcServerTest::handleWithTrue,
        //                     this,
        //                     std::placeholders::_1,
        //                     std::placeholders::_2)};
        //             SetHandler(cServiceId, cTrueMethodId, _handleWithTrue);

        //             auto _handleWithFalse{
        //                 std::bind(
        //                     &RpcServerTest::handleWithFalse,
        //                     this,
        //                     std::placeholders::_1,
        //                     std::placeholders::_2)};
        //             SetHandler(cServiceId, cFalseMethodId, _handleWithFalse);
        //         }

        //         uint32_t RpcServerTest::GetMessageId(uint16_t serviceId, uint16_t methodId)
        //         {
        //             auto _result{static_cast<uint32_t>(serviceId << 16)};
        //             _result |= methodId;

        //             return _result;
        //         }

        //         bool RpcServerTest::handleWithTrue(
        //             const std::vector<uint8_t> &rpcRequestPdu,
        //             std::vector<uint8_t> &rpcResponsePdu) const
        //         {
        //             return true;
        //         }

        //         bool RpcServerTest::handleWithFalse(
        //             const std::vector<uint8_t> &rpcRequestPdu,
        //             std::vector<uint8_t> &rpcResponsePdu) const
        //         {
        //             return false;
        //         }
        //     }
        // }
    }
}