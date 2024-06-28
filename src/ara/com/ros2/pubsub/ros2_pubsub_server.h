#ifndef ROS2_PUBSUB_SERVER_H
#define ROS2_PUBSUB_SERVER_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"

namespace ara
{
    namespace com
    {
        namespace ros2
        {
            namespace pubsub
            {
                class ROS2PubSubServer
                {
                public:
                    ROS2PubSubServer();

                    void PublishMessage(const std::vector<uint8_t>& payload);

                private:
                    rclcpp::Node::SharedPtr ros_node;
                    rclcpp::Publisher<std_msgs::msg::ByteMultiArray>::SharedPtr ros_publisher;
                };
            }
        }
    }
}

#endif // ROS2_PUBSUB_SERVER_H
