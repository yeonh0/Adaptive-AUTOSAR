#include "../../../../src/ara/com/someip/rpc/someip_rpc_server.h"
#include "../../../../src/ara/com/someip/someip_message.h"
#include "../../../../src/ara/core/instance_specifier.h"
#include "rclcpp/rclcpp.hpp"
#include "../../../../../../opt/ros/humble/include/example_interfaces/example_interfaces/srv/add_two_ints.hpp"

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
                    void add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
                             std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response);
                    AsyncBsdSocketLib::Poller poller;

                    static void signalHandler(int signum);

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
                    std::shared_ptr<rclcpp::Node> node;

                    mySkeleton();

                    void create(int argc, char **argv);

                    void onr();

                    ~mySkeleton();
            };
        }
    }
}