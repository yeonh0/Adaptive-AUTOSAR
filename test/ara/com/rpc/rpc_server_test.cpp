#include "rpc_server_test.h"

using namespace std;

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            RpcServerTest::RpcServerTest(
                 AsyncBsdSocketLib::Poller *poller,
                std::string ipAddress,
                uint16_t port,
                uint8_t protocolVersion,
                uint8_t interfaceVersion = 1)
                : SocketRpcServer(poller, ipAddress, port, protocolVersion, interfaceVersion)
            {
                cout << "Server on" << endl;
            }
        }
    }
}
            // void RpcServerTest::readMsg()
            // {
            //     if (socketRpcServer)
            //     {
            //         socketRpcServer->onReceive(); // Directly call onReceive
            //     }
            //     else
            //     {
            //         std::cerr << "SocketRpcServer is not set." << std::endl;
            //     }
            // }

        //     uint32_t RpcServerTest::GetMessageId(uint16_t serviceId, uint16_t methodId)
        //     {
                
        //         return 0;
        //     }
        // }

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