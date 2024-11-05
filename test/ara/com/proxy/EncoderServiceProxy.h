#ifndef ENCODERPROXY_H
#define ENCODERPROXY_H

#include "../../../../src/ara/com/someip/sd/sd_network_layer.h"
#include "../../../../src/ara/com/someip/sd/someip_sd_message.h"
#include "../../../../src/ara/com/entry/service_entry.h"
#include "../../../../src/ara/com/someip/sd/someip_sd_client.h"
#include "../../../../src/ara/com/helper/machine_state.h"
#include "../../../../src/ara/com/someip/pubsub/someip_pubsub_client.h"
#include "../../../../src/ara/com/proxy/events/EncoderSampleType.cpp"

#include <memory>
#include <deque>
#include <array>
#include <iostream>
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
                static std::vector<std::unique_ptr<proxy::EncoderServiceProxy>> FindService(std::vector<std::string> specifier);

                /// @brief Create Encoder Event subscriber
                /// @param queue_size Event receive queue size
                void subscribeEncoderEvent(int queue_size);

                /// @brief Set Encoder Event subscribe handler
                /// @param handler handler function
                void setEncoderEventReceiveHandler(std::function<void()>& handler);

                /// @brief Get Encoder event sample
                /// @param callback Sample handler function
                void getNewSamples(std::function<void(std::shared_ptr<ara::com::proxy::events::EncoderEvent::EncoderSampleType>)> callback);

            private:
                std::shared_ptr<ara::com::someip::pubsub::SomeIpPubSubClient> SomeIpPubSubClient;
            };
        }
    }
}

#endif // ENCODERPROXY_H
