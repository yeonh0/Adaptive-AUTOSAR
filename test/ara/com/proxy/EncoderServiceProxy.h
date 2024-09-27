#ifndef ENCODERPROXY_H
#define ENCODERPROXY_H

#include "../../../../src/ara/com/entry/service_entry.h"
#include "../../../../src/ara/com/helper/machine_state.h"
#include "../../../../src/ara/com/proxy/events/EncoderSampleType.cpp"
#include "../../../../src/ara/core/instance_specifier.h"
#include "vsomeip/vsomeip.hpp"

#include <memory>
#include <deque>
#include <array>
#include <iostream>
#include <iomanip>

#include <condition_variable>
#include <thread>

namespace ara
{
    namespace com
    {
        namespace proxy
        {
            /// @brief Encoder Event proxy
            class EncoderServiceProxy
            {
            public:
                EncoderServiceProxy();
                ~EncoderServiceProxy();
                
                /// @brief SOME/IP service discovery static function
                static std::vector<std::unique_ptr<proxy::EncoderServiceProxy>> FindService(ara::core::InstanceSpecifier specifier);

                /// @brief Create Encoder Event subscriber
                /// @param queue_size Event receive queue size
                void subscribeEncoderEvent(int queue_size);

                void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available);

                void on_message(const std::shared_ptr<vsomeip::message> &_request);

                void runSomeip();

                void subscriber();

                /// @brief Set Encoder Event subscribe handler
                /// @param handler handler function
                void setEncoderEventReceiveHandler(std::function<void()>& handler);

                /// @brief Get Encoder event sample
                /// @param callback Sample handler function
                void getNewSamples(std::function<void(std::shared_ptr<ara::com::proxy::events::EncoderEvent::EncoderSampleType>)> callback);

            private:
                std::thread someipThread;
                std::thread subscriberThread;

                std::shared_ptr< vsomeip::application > encoderProxyApp;
                uint16_t SERVICE_ID = 0x1234;
                uint16_t INSTANCE_ID = 0x5678;
                uint16_t EVENTGROUP_ID = 0x4465;
                uint16_t EVENT_ID = 0x8778;
                uint16_t METHOD_ID = 0x0421;
                std::mutex mutex;
                std::condition_variable condition;
            };
        }
    }
}

#endif // ENCODERPROXY_H
