#ifndef AHRSPROXY_H
#define AHRSPROXY_H

#include "../../../../src/ara/com/ros2/pubsub/ros2_pubsub_client.h"

#include <memory>
#include <deque>
#include <array>
#include <iostream>
#include <thread>
#include <vector>

namespace ara
{
    namespace com
    {
        namespace proxy
        {
            /// @brief AHRS Event proxy
            class AhrsServiceProxy
            {
            public:
                AhrsServiceProxy();
                ~AhrsServiceProxy();

                 /// @brief ROS2 service discovery static function
                static std::vector<std::unique_ptr<proxy::AhrsServiceProxy>> FindService();
                
                /// @brief Create IMU Event subscriber
                /// @param queue_size Event receive queue size
                void subscribeIMUEvent(int queue_size);

                /// @brief Set IMU Event subscribe handler
                /// @param handler handler function
                void setIMUEventReceiveHandler(std::function<void()>& handler);

                /// @brief Get IMU event sample
                /// @param callback Sample handler function
                void getNewSamples(std::function<void(std::shared_ptr<ara::com::proxy::events::IMUEvent::IMUSampleType>)> callback);

            private:
                std::shared_ptr<ara::com::ros2::pubsub::ROS2PubSubClient> client;
            };
        }
    }
}

#endif // AHRSPROXY_H
