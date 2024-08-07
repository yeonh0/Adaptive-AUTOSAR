#ifndef PROXY_H
#define PROXY_H

#include "../../../../src/ara/com/ros2/pubsub/ros2_pubsub_client.h"
#include "../../../../src/ara/com/someip/sd/sd_network_layer.h"
#include "../../../../src/ara/com/someip/sd/someip_sd_message.h"
#include "../../../../src/ara/com/entry/service_entry.h"
#include "../../../../src/ara/com/someip/sd/someip_sd_client.h"
#include "../../../../src/ara/com/helper/machine_state.h"

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
                AhrsServiceProxy(const std::string &nicIpAddress, const std::string &multicastGroup, uint16_t port);
                ~AhrsServiceProxy();
                
                void findService();
                void subscribeIMUEvent(int queue_size);
                void setIMUEventReceiveHandler(std::function<void()>& handler);
                void getNewSamples(std::function<void(std::shared_ptr<ara::com::proxy::events::BrakeEvent::SampleType>)> callback);
                void HI();

            private:
                std::shared_ptr<ara::com::ros2::pubsub::ROS2PubSubClient> client;

                AsyncBsdSocketLib::Poller poller;
                someip::sd::SdNetworkLayer mNetworkLayer;

                uint16_t serviceId = 0x1234;
                int initialDelayMin = 10;
                int initialDelayMax = 50;

            protected:
                ara::com::someip::sd::SomeIpSdClient sdClient;
                const int WaitDuration;
                static const std::string cIpAddress;
                static const uint16_t cPort;
            };
        }
    }
}

#endif // PROXY_H
