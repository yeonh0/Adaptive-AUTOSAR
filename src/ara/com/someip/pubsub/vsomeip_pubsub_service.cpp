#include "vsomeip_pubsub_service.h"
#include <thread>

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace pubsub
            {
               VsomeIpPubSubServer::VsomeIpPubSubServer(
                        const std::string &_name,
                        uint16_t serviceId,
                        uint16_t instanceId): application_(vsomeip::runtime::get()->create_application(_name)),
                                                mServiceId{serviceId},
                                                mInstanceId{instanceId}
                {
                    mStateMachine.Initialize({&mServiceDownState,
                                              &mNotSubscribedState,
                                              &mSubscribedState},
                                             helper::PubSubState::ServiceDown);

                }

                bool VsomeIpPubSubServer::init() {
                    if (!application_->init())
                        return (false);

                    helper::PubSubState _state = GetState();
                    if (_state == helper::PubSubState::ServiceDown)
                    {
                        mServiceDownState.Started();
                    }
                    return true;
                }

                bool VsomeIpPubSubServer::isConnected() const {
                    helper::PubSubState _state = GetState();
                    return (_state == helper::PubSubState::Subscribed);
                }

                void VsomeIpPubSubServer::sendEvent(service_t _service, instance_t _instance,
                         event_t _event, std::shared_ptr<payload> _payload, int interval_ms)
                {
                    mEventThread = std::make_shared<std::thread>([=]() {
                        while (mRunning) {
                            application_->notify(_service, _instance, _event, _payload, true);
                            std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
                        }
                    });
                }

                void VsomeIpPubSubServer::StopEvent()
                {
                    mRunning = false;
                    if (mEventThread && mEventThread->joinable()) {
                        mEventThread->join();
                    }
                }

                void VsomeIpPubSubServer::VsomeIpPubSubServer::dispatch() 
                {
                    application_->start();
                }

                void VsomeIpPubSubServer::offerService(service_t _service, instance_t _instance)
                {
                    application_->offer_service(_service, _instance);
                }

                void VsomeIpPubSubServer::registerEvent(service_t _service, instance_t _instance,
                        event_t _event, const std::set<eventgroup_t> &_eventGroups)
                {
                    application_->offer_event(_service, _instance, _event, _eventGroups);
                }

                void VsomeIpPubSubServer::unregisterEvent(service_t _service, instance_t _instance,
                        event_t _event)
                {
                    application_->stop_offer_event(_service, _instance, _event);
                }

                helper::PubSubState VsomeIpPubSubServer::GetState() const noexcept
                {
                    return mStateMachine.GetState();
                }

                void VsomeIpPubSubServer::Stop()
                {
                    helper::PubSubState _state = GetState();
                    if (_state == helper::PubSubState::NotSubscribed)
                    {
                        mNotSubscribedState.Stopped();
                    }
                    else if (_state == helper::PubSubState::Subscribed)
                    {
                        mSubscribedState.Stopped();
                    }
                    application_->stop();
                }

                VsomeIpPubSubServer::~VsomeIpPubSubServer()
                {
                    this->Stop();
                }
            }
        }
    }
}
