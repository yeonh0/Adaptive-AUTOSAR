#ifndef VSOMEIP_PUBSUB_CLIENT
#define VSOMEIP_PUBSUB_CLIENT

#include <condition_variable>
#include <iomanip>
#include <iostream>
#include <vector>
#include <thread>

#include "../../entry/eventgroup_entry.h"
#include "../../helper/concurrent_queue.h"
#include <vsomeip/vsomeip.hpp>
#include <vsomeip/primitive_types.hpp>
using namespace vsomeip_v3;

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace pubsub
            {
                /// @brief SOME/IP publish/subscribe client
                class VsomeIpPubSubClient:
                    public std::enable_shared_from_this<VsomeIpPubSubClient>
                {
                private:
                    helper::ConcurrentQueue<vsomeip::message> mMessageBuffer;
                    std::mutex mSubscriptionMutex;
                    std::unique_lock<std::mutex> mSubscriptionLock;
                    std::condition_variable mSubscriptionConditionVariable;
                    bool mValidNotify;

                    std::mutex mMutex;
                    std::condition_variable mCondition;

                    service_t mService;
                    service_t mInstance;
                    event_t mEvent;
                    eventgroup_t mEventGroup;

                    std::shared_ptr<std::thread> mSender;

                protected:
                    void on_availability(
                        vsomeip::service_t _service, 
                        vsomeip::instance_t _instance, 
                        bool _is_available);

                    void on_message(const std::shared_ptr<vsomeip::message> &_response);

                    

                public:
                    std::shared_ptr< vsomeip::application > application_;
                    VsomeIpPubSubClient() = delete;
                    ~VsomeIpPubSubClient();

                    /// @brief Constructor
                    /// @param _name Name of Client application
                    VsomeIpPubSubClient(
                        const std::string &_name);

                    void run();

                    /// @brief Subscribe to an event-group
                    /// @param _service Service in interest ID
                    /// @param _instance Service in interest instance ID
                    /// @param _event Service in interest event ID
                    void Subscribe(
                        service_t _service, 
                        instance_t _instance,
                        event_t _event,
                        eventgroup_t _egroup);

                    /// @brief Unsubscribe from a subscribed event-group
                    /// @param _service Service in interest ID
                    /// @param _instance Service in interest instance ID
                    /// @param _event Service in interest event ID
                    void Unsubscribe(
                        service_t _service, 
                        instance_t _instance,
                        event_t _event);

                    bool init();

                    void requestService(
                        service_t _service, 
                        instance_t _instance);

                    /// @brief Start vsomeip applcation
                    void dispatch();

                    void makeHandler();

                    /// @brief Stop the client
                    void Stop();
                };
            }
        }
    }
}

#endif