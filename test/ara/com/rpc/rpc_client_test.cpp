#include "rpc_client_test.h"

using namespace std;

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            AsyncBsdSocketLib::Poller* RpcClientTest::poller = nullptr;
            const std::string RpcClientTest::ipAddress = "0.0.0.0";
            const uint16_t RpcClientTest::port{1234};
            const uint8_t RpcClientTest::protocolVersion{1};
            const uint8_t RpcClientTest::interfaceVersion{1};

            RpcClientTest::RpcClientTest()
                : someipClient(poller, ipAddress, port, protocolVersion, interfaceVersion)
            {
                cout << "someip rpc Client start" << endl;
            }

            void RpcClientTest::setPoller(AsyncBsdSocketLib::Poller* p) {
                poller = p;
            }

        }
    }
}
