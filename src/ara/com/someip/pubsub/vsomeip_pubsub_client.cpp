 #include "vsomeip_pubsub_client.h"

namespace ara
{
    namespace com
    {
        namespace someip
        {
            namespace pubsub
            {
                VsomeIpPubSubClient::VsomeIpPubSubClient(const std::string &_name) 
                    :   application_(vsomeip::runtime::get()->create_application(_name)),
                        mSubscriptionLock(mSubscriptionMutex, std::defer_lock),
                        mValidNotify{true}
                { }

                void VsomeIpPubSubClient::on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available) {
                    std::cout << "Service ["
                    << std::setw(4) << std::setfill('0') << std::hex << _service << "." << _instance
                    << "] is " << (_is_available ? "available." : "NOT available.")  << std::endl;
                    mCondition.notify_one();
                }

                void VsomeIpPubSubClient::on_message(const std::shared_ptr<vsomeip::message> &_response) {
                    std::stringstream its_message;
                    its_message << "CLIENT: received a notification for event ["
                            << std::setw(4) << std::setfill('0') << std::hex
                            << _response->get_service() << "."
                            << std::setw(4) << std::setfill('0') << std::hex
                            << _response->get_instance() << "."
                            << std::setw(4) << std::setfill('0') << std::hex
                            << _response->get_method() << "] to Client/Session ["
                            << std::setw(4) << std::setfill('0') << std::hex
                            << _response->get_client() << "/"
                            << std::setw(4) << std::setfill('0') << std::hex
                            << _response->get_session()
                            << "] = ";
                    std::shared_ptr<vsomeip::payload> its_payload = _response->get_payload();
                    its_message << "(" << std::dec << its_payload->get_length() << ") ";
                    for (uint32_t i = 0; i < its_payload->get_length(); ++i)
                        its_message << std::hex << std::setw(2) << std::setfill('0')
                            << (int) its_payload->get_data()[i] << " ";
                    std::cout << its_message.str() << std::endl;
                }

                void VsomeIpPubSubClient::run() {
                    std::unique_lock<std::mutex> its_lock(mMutex);
                    mCondition.wait(its_lock);

                    std::set<vsomeip::eventgroup_t> its_groups;
                    its_groups.insert(mEventGroup);
                    application_->request_event(mService, mInstance, mEvent, its_groups);
                    application_->subscribe(mService, mInstance, mEventGroup);
                }

                void VsomeIpPubSubClient::Subscribe(
                        service_t _service, 
                        instance_t _instance,
                        event_t _event,
                        eventgroup_t _egroup)
                {
                    mService = _service, mInstance = _instance, mEvent = _event, mEventGroup = _egroup;

                    if (mSender && mSender->joinable()) {
                        mSender->join();
                    }

                    mSender = std::make_shared<std::thread>(&VsomeIpPubSubClient::run, shared_from_this());
                }
                
                void VsomeIpPubSubClient::Unsubscribe(
                        service_t _service, 
                        instance_t _instance,
                        event_t _event)
                {
                    application_->release_event(_service, _instance, _event);
                }

                bool VsomeIpPubSubClient::init()
                {
                    if (!application_->init())
                        return false;
                    return true;
                }

                void VsomeIpPubSubClient::requestService(
                                            service_t _service, 
                                            instance_t _instance) 
                {
                    mService = _service, mInstance = _instance;
                    application_->request_service(_service, _instance);
                }

                void VsomeIpPubSubClient::makeHandler()
                {
                    auto serviceHandler = std::bind(
                        &VsomeIpPubSubClient::on_availability, 
                        shared_from_this(),
                        std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
                    application_->register_availability_handler(mService, mInstance, serviceHandler);

                    auto messageHandler = std::bind(
                        &VsomeIpPubSubClient::on_message,
                        shared_from_this(),
                        std::placeholders::_1);
                    application_->register_message_handler(vsomeip::ANY_SERVICE, vsomeip::ANY_INSTANCE, vsomeip::ANY_METHOD, messageHandler);
                }

                void VsomeIpPubSubClient::dispatch()
                {
                    application_->start();
                }

                void VsomeIpPubSubClient::Stop()
                {
                    application_->stop();
                }

                VsomeIpPubSubClient::~VsomeIpPubSubClient()
                {
                    if (mSender && mSender->joinable()) {
                        mSender->join();
                    }
                    this->Stop();
                }
            }
        }
    }
}