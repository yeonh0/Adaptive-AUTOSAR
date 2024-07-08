#include "skeleton.h"

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            bool mySkeleton::handleResponse(const std::vector<uint8_t>& request, std::vector<uint8_t>& response) const
            {
                for (auto byte : request) {
                    std::cout << byte;
                }
                std::cout << std::endl;

                response = request;
                
                return true;
            }

            const std::string mySkeleton::serverIpAddress = "0.0.0.0";
            const uint16_t mySkeleton::serverPort = 33333;
            const uint8_t mySkeleton::protocolVersion = 1;
            const uint8_t mySkeleton::interfaceVersion = 1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            mySkeleton::mySkeleton()
                :server(&poller, serverIpAddress, serverPort, protocolVersion, interfaceVersion)
            {
                // ros2 service server

                // someip SetHandler
                auto _handler = std::bind(
                                &mySkeleton::handleResponse,
                                this,
                                std::placeholders::_1,
                                std::placeholders::_2);
                                
                server.SetHandler(serviceId, SetSpeed_methodId, _handler);
            }

            void mySkeleton::onr()
            {
                server.onReceive();
            }

            mySkeleton::~mySkeleton()
            {
            }
        }
    }
}