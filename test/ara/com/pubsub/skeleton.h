#ifndef SKELETON_H
#define SKELETON_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <atomic>

#include "asyncbsdsocket/poller.h"
#include "../../../../src/ara/com/someip/sd/sd_network_layer.h"
#include "../../../../src/ara/com/someip/sd/someip_sd_message.h"
#include "../../../../src/ara/com/entry/service_entry.h"
#include "../../../../src/ara/com/someip/sd/someip_sd_server.h"
#include "../../../../src/ara/com/helper/machine_state.h"
#include "../../../../src/ara/com/someip/pubsub/someip_pubsub_message.h"

namespace ara
{
    namespace com
    {
        namespace pubsub
        {
            class Skeleton
            {
            public:
                Skeleton(AsyncBsdSocketLib::Poller *poller, const std::string &nicIpAddress, const std::string &multicastGroup, uint16_t port);
                ~Skeleton();
                void init();
                void Stop();
                void OfferService();
                
            private:
                AsyncBsdSocketLib::Poller *const mPoller;
                someip::sd::SdNetworkLayer mNetworkLayer;
                someip::sd::SomeIpSdServer SDServer;
                bool running;

                static const uint16_t cServiceId = 0x1234;
                static const uint16_t cInstanceId = 1;
                static const uint8_t cMajorVersion = 1;
                static const uint32_t cMinorVersion = 0;
                static const int cInitialDelayMin = 100;
                static const int cInitialDelayMax = 200;
                static const int cRepetitionBaseDelay = 200;
                static const uint32_t cRepetitionMax = 2;
                static const int cCycleOfferDelay = 100;

                helper::Ipv4Address sdIP;
                const std::string cIP = "172.24.125.198";
                static const uint16_t cPort = 33333;

                std::atomic<bool> stopAsyncTask;
                std::future<void> future;
            };
        }
    }
}

#endif // SKELETON_H
