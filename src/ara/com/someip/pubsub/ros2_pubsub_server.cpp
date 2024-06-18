#include "ros2_pubsub_server.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace pubsub
            {
                ROS2PubSubServer::ROS2PubSubServer()
                {
                    rclcpp::init(0, nullptr);
                    ros_node = rclcpp::Node::make_shared("ros2_pubsub_node");
                    ros_publisher = ros_node->create_publisher<std_msgs::msg::ByteMultiArray>("someip_pubsub_topic", 10);
                }

                void ROS2PubSubServer::PublishMessage(const std::vector<uint8_t>& payload)
                {
                    // 페이로드 출력
                    std::cout << "Payload: ";
                    for (const auto &byte : payload)
                    {
                        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
                    }
                    std::cout << std::dec << std::endl; // Reset to decimal formatting

                    // ROS2 메시지 생성 및 퍼블리시
                    auto ros_message = std_msgs::msg::ByteMultiArray();
                    ros_message.data = payload;
                    ros_publisher->publish(ros_message);

                    // Spin 로직을 추가하여 메시지가 퍼블리시되는지 확인
                    rclcpp::spin_some(ros_node);
                }
            }
        }
    }
}
