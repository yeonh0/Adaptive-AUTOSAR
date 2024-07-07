#include "../../../../src/ara/com/someip/rpc/someip_rpc_client.h"

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            class myProxy
            {
            private:
                AsyncBsdSocketLib::Poller poller;

            protected:
                static const std::string serverIpAddress;
                static const uint16_t serverPort;
                static const uint8_t protocolVersion;
                static const uint8_t interfaceVersion;

                SomeIpClient client;

            public:
                myProxy();
                
                void CallService(
                uint16_t serviceId,
                uint16_t methodId,
                uint16_t clientId,
                std::vector<uint8_t> rpcPayload);
            };
        }
    }
}
