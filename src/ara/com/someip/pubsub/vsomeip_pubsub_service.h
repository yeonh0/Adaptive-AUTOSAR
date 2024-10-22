#ifndef VSOMEIP_PUBSUB_SERVICE
#define VSOMEIP_PUBSUB_SERVICE

#include "../../helper/finite_state_machine.h"
#include "../../entry/eventgroup_entry.h"
#include "./fsm/service_down_state.h"
#include "./fsm/notsubscribed_state.h"
#include "./fsm/subscribed_state.h"
#include <vsomeip/vsomeip.hpp>
#include <vsomeip/primitive_types.hpp>
#include <thread>
using namespace vsomeip_v3;

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace pubsub
            {
                /// @brief SOME/IP publish/subscribe server
                class VsomeIpPubSubServer
                {
                private:
                    helper::FiniteStateMachine<helper::PubSubState> mStateMachine;
                    std::shared_ptr< vsomeip::application > application_;
                    const instance_t mInstanceId;
                    const service_t mServiceId;
                    fsm::ServiceDownState mServiceDownState;
                    fsm::NotSubscribedState mNotSubscribedState;
                    fsm::SubscribedState mSubscribedState;
                    std::shared_ptr<std::thread> mEventThread;
                    bool mRunning = true;

                public:
                    VsomeIpPubSubServer() = delete;
                    ~VsomeIpPubSubServer();

                    /// @brief Constructor
                    /// @param networkLayer Network communication abstraction layer
                    /// @param serviceId Service ID
                    /// @param instanceId Service instance ID
                    VsomeIpPubSubServer(
                        const std::string &_name,
                        uint16_t serviceId,
                        uint16_t instanceId);

                    bool init();

                    bool isConnected() const;

                    void sendEvent(service_t _service, instance_t _instance,
                            event_t _event, std::shared_ptr<vsomeip::payload> _payload, int interval_ms);

                    void StopEvent();

                    /// @brief Start vsomeip applcation
                    void dispatch();
                    
                    void offerService(service_t _service, instance_t _instance);

                    /// @brief Register service
                    void registerEvent(service_t _service, instance_t _instance,
                        event_t _event, const std::set<eventgroup_t> &_eventGroups);

                    /// @brief Unregister service
                    /// @param _service service id
                    /// @param _instance instance id
                    /// @param _event event id
                    void unregisterEvent(service_t _service, instance_t _instance,
                        event_t _event);

                    /// @brief Get the current server state
                    /// @returns Server machine state
                    helper::PubSubState GetState() const noexcept;

                    /// @brief Stop the server
                    void Stop();
                };
            }
        }
    }
}

#endif