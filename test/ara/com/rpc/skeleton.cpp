#include "skeleton.h"

namespace ara
{
    namespace com
    {
        namespace rpc
        {
            const std::string mySkeleton::serverIpAddress = "0.0.0.0";
            const uint16_t mySkeleton::serverPort = 33333;
            const uint8_t mySkeleton::protocolVersion = 1;
            const uint8_t mySkeleton::interfaceVersion = 1;

            mySkeleton::mySkeleton()
                : server(&poller, serverIpAddress, serverPort, protocolVersion, interfaceVersion)
            {
            }

            void mySkeleton::signalHandler(int signum)
            {
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Signal (%d) received. Shutting down...", signum);
                rclcpp::shutdown();
                std::exit(signum);
            }

            void mySkeleton::create(int argc, char **argv)
            {
                // ROS2 INIT
                rclcpp::init(argc, argv);
                mySkeleton::node = rclcpp::Node::make_shared("add_two_ints_server");

                auto _roshandler = std::bind(
                                &mySkeleton::add,
                                this,
                                std::placeholders::_1,
                                std::placeholders::_2);

                rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service =
                    node->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", _roshandler);

                // SOMEIP SetHandler
                auto _handler = std::bind(
                                &mySkeleton::handleResponse,
                                this,
                                std::placeholders::_1,
                                std::placeholders::_2);
                                
                server.SetHandler(serviceId, SetSpeed_methodId, _handler);

                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");

                signal(SIGINT, mySkeleton::signalHandler);

                while(rclcpp::ok()) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    rclcpp::spin_some(mySkeleton::node);

                    server.onReceive();
                    server.onSend();
                }
            }

            bool mySkeleton::handleResponse(const std::vector<uint8_t>& request, std::vector<uint8_t>& response) const
            {
                int sum = 0;
                for (auto byte : request) {
                    sum += byte;
                }
                response.push_back(sum);
                return true;
            }

            void mySkeleton::add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
                    std::shared_ptr<example_interfaces::srv::AddTwoInts::Response>      response)
            {
                response->sum = request->a + request->b;
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
                                request->a, request->b);
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
            }

            void mySkeleton::onr()
            {
            }

            mySkeleton::~mySkeleton()
            {
            }
        }
    }
}