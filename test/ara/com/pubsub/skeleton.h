#ifndef SKELETON_H
#define SKELETON_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <atomic>

#include "../../../../src/ara/com/someip/sd/someip_sd_message.h"
#include "../../../../src/ara/com/entry/service_entry.h"
#include "../../../../src/ara/com/helper/machine_state.h"
#include "../../../../src/ara/com/someip/pubsub/someip_pubsub_message.h"

#include "../../../../src/ara/core/instance_specifier.h"
#include "../../../../src/ara/core/result.h"
#include "../../../../src/ara/com/proxy/events/EncoderSampleType.cpp"
#include "vsomeip/vsomeip.hpp"

namespace ara
{
    namespace com
    {
        namespace pubsub
        {
            class EncoderServiceSkeleton
            {
            public:
                EncoderServiceSkeleton(core::InstanceSpecifier instanceId);
                ~EncoderServiceSkeleton();
                void init();
                ara::core::Result<void> OfferService();
                void StopOfferService();
                void runSomeip();
                
            private:
                std::thread someipThread;

                // vsomeip lib
                std::shared_ptr< vsomeip::application > app;
                std::shared_ptr<vsomeip::payload> payload;
                std::set<vsomeip::eventgroup_t> its_groups;

                proxy::events::EncoderEvent EncoderEvent;

                uint16_t EVENTGROUP_ID = 0x4465;
                uint16_t EVENT_ID = 0x8778;
                uint16_t SERVICE_ID = 0x1234;
                uint16_t INSTANCE_ID = 0x5678;
            };
        }
    }
}

#endif // SKELETON_H
