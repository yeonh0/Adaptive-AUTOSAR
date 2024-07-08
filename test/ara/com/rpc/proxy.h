#include "../../../../src/ara/com/someip/rpc/someip_rpc_client.h"
#include "../../../../src/ara/com/someip/someip_message.h"

#include <iostream>
#include <iomanip>

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
                void handleResponse(const someip::SomeIpMessage &response) const;
                
            protected:
                static const std::string serverIpAddress;
                static const uint16_t serverPort;
                static const uint8_t protocolVersion;
                static const uint8_t interfaceVersion;

                static const uint16_t clientId = 0x0001;
                static const uint16_t serviceId = 0x1234;
                static const uint16_t SetSpeed_methodId = 0x5678;

                SomeIpRpcClient client;

            public:
                myProxy();
                
                void SetSpeed(
                    std::vector<uint8_t> rpcPayload,
                    std::vector<uint8_t> rpcResponse);
            };
        }
    }
}
