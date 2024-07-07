#include "someip_rpc_client.h"

using namespace std;

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            AsyncBsdSocketLib::Poller SomeIpClient::defaultPoller;
            const std::string SomeIpClient::defaultIpAddress = "127.0.0.1";

            SomeIpClient::SomeIpClient(
                AsyncBsdSocketLib::Poller *poller,
                std::string ipAddress,
                uint16_t port,
                uint8_t protocolVersion,
                uint8_t interfaceVersion)
                : SocketRpcClient(poller, ipAddress, port, protocolVersion, interfaceVersion)
            {
            }

            void SomeIpClient::SendRpcMessage(uint16_t serviceId, uint16_t methodId, uint16_t clientId, const std::vector<uint8_t> &rpcPayload)
            {
                // RpcClient::Send -> Send SOME/IP RPC Msg
                RpcClient::Send(serviceId, methodId, clientId, rpcPayload);

                // SocketRpcClient::onSend -> Send TCP Msg in Msg Queue
                onSend();

                cout << "send completed" << endl;
            }
        }
    }
}
