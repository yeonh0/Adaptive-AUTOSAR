#include "ros2_rpc_server.h"

namespace ara
{
    namespace com
    {
        namespace ros2
        {
            namespace rpc
            {
                ROS2RpcServer::ROS2RpcServer()
                    : Node("ros2_rpc_server")
                {
                    ros_service = this->create_service<std_srvs::srv::Trigger>(
                            "ros_service",
                            std::bind(&ROS2RpcServer::handle_service, this, std::placeholders::_1, std::placeholders::_2));
                };
                

                void ROS2RpcServer::handle_service(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
                                                    std::shared_ptr<std_srvs::srv::Trigger::Response> response) 
                {
                    RCLCPP_INFO(this->get_logger(), "Received service request");
                    response->success = true;
                    response->message = "Service call handled successfully";
                };
            }
        }
    }
}