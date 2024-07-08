#include "../../../../src/ara/com/someip/rpc/someip_rpc_server.h"
#include "../../../../src/ara/com/someip/someip_message.h"

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            class mySkeleton
            {
                private:
                    bool handleResponse(const std::vector<uint8_t>& request, std::vector<uint8_t>& response) const;
                    AsyncBsdSocketLib::Poller poller;

                protected:
                    static const std::string serverIpAddress;
                    static const uint16_t serverPort;
                    static const uint8_t protocolVersion;
                    static const uint8_t interfaceVersion;

                    static const uint16_t clientId = 0x0001;
                    static const uint16_t serviceId = 0x1234;
                    static const uint16_t SetSpeed_methodId = 0x5678;
                    
                    SomeIpRpcServer server;

                
                public:
                    mySkeleton();
                    
                    void onr();

                    ~mySkeleton();
            };
        }
    }
}