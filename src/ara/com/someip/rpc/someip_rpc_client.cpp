#include "someip_rpc_client.h"

using namespace std;

namespace ara
{
    namespace com
    {
        namespace rpc
        {   
            SomeIpRpcClient::SomeIpRpcClient(
                AsyncBsdSocketLib::Poller *poller,
                std::string ipAddress,
                uint16_t port,
                uint8_t protocolVersion,
                uint8_t interfaceVersion)
                : SocketRpcClient(poller, ipAddress, port, protocolVersion, interfaceVersion)
            {
            }

            // handleResponse : Change Session ID
            void SomeIpRpcClient::handleResponse(const someip::SomeIpMessage &response) const
            {
                LastSessionId = response.SessionId();
            }

            void SomeIpRpcClient::callMethodWithReply(uint16_t serviceId, uint16_t methodId, uint16_t clientId, const std::vector<uint8_t> &rpcPayload)
            {
                // Serialize -> SOMEIP Msg & Msg Queue in
                RpcClient::Send(serviceId, methodId, clientId, rpcPayload);

                // SocketRpcClient::onSend -> Send TCP Msg in Msg Queue
                onSend();
                cout << "Client - Send RPC Message" << endl;

                // Receive Msg -> Check payload and call handler
                onReceive();
            }

            void SomeIpRpcClient::setHandler(uint16_t serviceId, uint16_t methodId, HandlerType handler)
            {
                RpcClient::SetHandler(serviceId, methodId, handler);
            }
        }
    }
}
