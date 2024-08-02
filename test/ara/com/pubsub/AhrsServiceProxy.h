#ifndef PROXY_H
#define PROXY_H

#include "../../../../src/ara/com/ros2/pubsub/ros2_pubsub_client.h"

#include <memory>
#include <deque>
#include <array>
#include <iostream>
#include <thread>

namespace ara
{
    namespace com
    {
        namespace pubsub
        {
            class AhrsServiceProxy
            {
            public:
                AhrsServiceProxy();
                ~AhrsServiceProxy();
                
                void SubscribeIMUEvent(int queue_size);
                void SetIMUEventReceiveHandler(std::function<void()>& handler);
                void GetNewSamples(std::function<void(std::shared_ptr<ara::com::proxy::events::BrakeEvent::SampleType>)> callback);

            private:
                std::shared_ptr<ara::com::ros2::pubsub::ROS2PubSubClient> client;
                std::thread spin_thread_;
            };
        }
    }
}

#endif // PROXY_H
