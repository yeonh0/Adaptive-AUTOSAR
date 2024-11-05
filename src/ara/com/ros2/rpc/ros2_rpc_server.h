#ifndef ROS2_RPC_SERVER_H
#define ROS2_RPC_SERVER_H

#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/trigger.hpp"

namespace ara
{
    namespace com
    {
        namespace ros2
        {
            namespace rpc
            {
                class ROS2RpcServer : public rclcpp::Node
                {
                public:
                // INIT RPC Server
                    ROS2RpcServer();

                private:
                    void handle_service(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
                                        std::shared_ptr<std_srvs::srv::Trigger::Response> response);
                                        
                    rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr ros_service;
                };
            }
        }
    }
}

#endif // ROS2_RPC_SERVER_H
