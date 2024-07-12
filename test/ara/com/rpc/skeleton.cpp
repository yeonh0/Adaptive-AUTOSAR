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

            mySkeleton::mySkeleton(std::vector <ara::core::InstanceSpecifier> instanceIds)
                : ros2Future(ros2Promise.get_future().share()), someipFuture(someipPromise.get_future().share()), keepRunning(true)
            {
                for (auto id : instanceIds)
                {
                    if(id == "ROS2_Instance") {
                        ros2Thread = std::thread(&mySkeleton::runRos2, this, 0, nullptr);
                    }
                    if(id == "SOMEIP_Instance") {
                        someipThread = std::thread(&mySkeleton::runSomeIp, this);
                    }
                }
            }

            mySkeleton::~mySkeleton()
            {
                mySkeleton::StopOfferService();

                if (ros2Thread.joinable()) {
                    ros2Promise.set_value();
                    ros2Thread.join();
                }
                if (someipThread.joinable()) {
                    ros2Promise.set_value();
                    someipThread.join();
                }
            }

            void mySkeleton::runRos2(int argc, char **argv)
            {
                ros2Future.wait();

                rclcpp::init(argc, argv);
                node = rclcpp::Node::make_shared("add_two_ints_server");
                std::cout << "Start ROS2 Server" << std::endl;

                if (node) {
                    std::cout << "Creating ROS2 Service..." << std::endl;
                    
                    auto _roshandler = std::bind(
                    &mySkeleton::add,
                    this,
                    std::placeholders::_1,
                    std::placeholders::_2);

                    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service =
                        node->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", _roshandler);

                    if (service) {
                        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "ROS2 Service ready to add two ints.");
                    } else {
                        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to create ROS2 Service.");
                    }
                    
                    signal(SIGINT, mySkeleton::signalHandler);
                    while(keepRunning) {
                        //std::cout << "ROS2 Turn" << std::endl;
                        rclcpp::spin_some(node);
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    }
                    rclcpp::shutdown();
                }
            }

            void mySkeleton::runSomeIp()
            {
                server.reset(new SomeIpRpcServer(&poller, serverIpAddress, serverPort, protocolVersion, interfaceVersion));
                std::cout << "Start SomeIp Server" << std::endl;

                someipFuture.wait();

                if (server) {
                    auto _handler = std::bind(
                        &mySkeleton::handleResponse,
                        this,
                        std::placeholders::_1,
                        std::placeholders::_2);

                    server->SetHandler(serviceId, SetSpeed_methodId, _handler);
                    std::cout << "SOME/IP Service ready." << std::endl;
                }

                while (true) {
                    server->onReceive();
                    server->onSend();
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            }

            void mySkeleton::OfferService()
            {
                ros2Promise.set_value();
                someipPromise.set_value();
            }

            void mySkeleton::StopOfferService()
            {
                keepRunning = false;
            }

            void mySkeleton::signalHandler(int signum)
            {
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Signal (%d) received. Shutting down...", signum);
                std::exit(signum);
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
        }
    }
}