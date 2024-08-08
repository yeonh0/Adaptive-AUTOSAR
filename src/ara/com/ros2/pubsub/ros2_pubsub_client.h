#ifndef ROS2_PUBSUB_CLIENT_H
#define ROS2_PUBSUB_CLIENT_H

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "../../../../src/ara/com/proxy/events/IMUSampleType.cpp"

#include <deque>
#include <array>

using std::placeholders::_1;

namespace ara
{
    namespace com
    {
        namespace ros2
        {
            namespace pubsub
            {
                class ROS2PubSubClient
                {
                public:
                    ROS2PubSubClient();

                    ~ROS2PubSubClient();

                    void topic_callback(const std::shared_ptr<const sensor_msgs::msg::Imu> msg) const;

                    void startClient();

                    void runRos2();

                    void setCallback(std::function<void()>& handler);

                    std::shared_ptr<ara::com::proxy::events::IMUEvent::IMUSampleType> fetchsample();

                private:
                    rclcpp::Node::SharedPtr ros_node;
                    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr ros_subscriber;
                    std::function<void()> callbackhandler;
                    std::thread ros2Thread;
                    std::shared_ptr<ara::com::proxy::events::IMUEvent::IMUSampleType> sample;
                };
            }
        }
    }
}

#endif // ROS2_PUBSUB_CLIENT_H
