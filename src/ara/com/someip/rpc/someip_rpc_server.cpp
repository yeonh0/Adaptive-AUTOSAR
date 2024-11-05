#include "someip_rpc_server.h"

using namespace std;

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            SomeIpRpcServer::SomeIpRpcServer(
                AsyncBsdSocketLib::Poller *poller,
                std::string ipAddress,
                uint16_t port,
                uint8_t protocolVersion,
                uint8_t interfaceVersion = 1)
                : SocketRpcServer(poller, ipAddress, port, protocolVersion, interfaceVersion)
            {
                SocketRpcServer::onAccept();
                cout << "Server on" << endl;
            }

            void SomeIpRpcServer::onReceive()
            {
                SocketRpcServer::onReceive();
            }

        }
    }
}
