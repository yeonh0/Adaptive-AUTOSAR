#include "ros2_pubsub_client.h"

  namespace ara
  {
      namespace com
      {
          namespace ros2
          {
              namespace pubsub
              {
                ROS2PubSubClient::ROS2PubSubClient() : sample(std::make_shared<ara::com::proxy::events::BrakeEvent::SampleType>())
                {
                }

                void ROS2PubSubClient::topic_callback(const sensor_msgs::msg::Imu::SharedPtr msg) const
                {             
                    sample->orientation[0] = msg->orientation.x;
                    sample->orientation[1] = msg->orientation.y;
                    sample->orientation[2] = msg->orientation.z;

                    sample->angular_velocity[0] = msg->angular_velocity.x;
                    sample->angular_velocity[1] = msg->angular_velocity.y;
                    sample->angular_velocity[2] = msg->angular_velocity.z;

                    sample->linear_acceleration[0] = msg->linear_acceleration.x;
                    sample->linear_acceleration[1] = msg->linear_acceleration.y;
                    sample->linear_acceleration[2] = msg->linear_acceleration.z;
                    callbackhandler();
                }

                ROS2PubSubClient::~ROS2PubSubClient() {
                    if (ros2Thread.joinable()) {
                        ros2Thread.join();
                    }
                }

                void ROS2PubSubClient::startClient() {
                    int argc = 0;
                    char** argv = nullptr;
                    rclcpp::init(argc, argv);
                    
                    ros_node = rclcpp::Node::make_shared("ros2_pubsub_client");
                    ros_subscriber = ros_node->create_subscription<sensor_msgs::msg::Imu>(
                                        "/imu/data", 10, std::bind(&ROS2PubSubClient::topic_callback, this, _1));

                    ros2Thread = std::thread(&ROS2PubSubClient::runRos2, this);
                }

                void ROS2PubSubClient::runRos2() {
                    rclcpp::spin(ros_node);
                    rclcpp::shutdown();
                }

                void ROS2PubSubClient::setCallback(std::function<void()>& handler) {
                    callbackhandler = handler;
                }

                std::shared_ptr<ara::com::proxy::events::BrakeEvent::SampleType> ROS2PubSubClient::fetchsample() {
                    return this->sample;
                }
              }
          }
      }
  }
