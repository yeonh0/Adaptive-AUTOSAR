#include "../../../../src/ara/com/someip/rpc/someip_rpc_server.h"
#include "../../../../src/ara/com/someip/someip_message.h"
#include "../../../../src/ara/core/instance_specifier.h"
#include "../../../../src/ara/core/result.h"
#include "../../../../src/ara/core/error_code.h"
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
                    // Ros2 & Someip Callback Function
                    bool handleResponse(const std::vector<uint8_t>& request, std::vector<uint8_t>& response) const;
                    void add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
                             std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response);
                    
                    // Ros2 Signal Handler
                    static void signalHandler(int signum);

                protected:
                    // Someip Server Init
                    AsyncBsdSocketLib::Poller poller;
                    static const std::string serverIpAddress;
                    static const uint16_t serverPort;
                    static const uint8_t protocolVersion;
                    static const uint8_t interfaceVersion;

                    // Someip Message Init
                    static const uint16_t clientId = 0x0001;
                    static const uint16_t serviceId = 0x1234;
                    static const uint16_t SetSpeed_methodId = 0x5678;

                    // Thread
                    std::thread ros2Thread;
                    std::thread someipThread;

                    // Promise & Future
                    std::promise<void> ros2Promise, someipPromise;
                    std::shared_future<void> ros2Future, someipFuture;

                    std::atomic<bool> keepRunning;
                    
                
                public:
                    // Constructor & Destructor 
                    mySkeleton(std::vector <ara::core::InstanceSpecifier> instanceIds);
                    ~mySkeleton();

                    // Ros2 node & Someip server
                    std::shared_ptr<rclcpp::Node> node;
                    std::unique_ptr<SomeIpRpcServer> server;

                    // Run Ros2 & Someip
                    void runRos2(int argc, char **argv);
                    void runSomeIp();

                    // Start & Stop Offer Service
                    void OfferService();
                    void StopOfferService();
            };
        }
    }
}