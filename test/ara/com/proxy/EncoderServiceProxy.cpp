#include "EncoderServiceProxy.h"

namespace ara
{
    namespace com
    {
        namespace proxy
        {
            EncoderServiceProxy::EncoderServiceProxy()
            {
            }

            EncoderServiceProxy::~EncoderServiceProxy()
            {
                if (someipThread.joinable()) {
                    someipThread.join();
                }
                if (subscriberThread.joinable()) {
                    subscriberThread.join();
                }
            }

            std::vector<std::unique_ptr<proxy::EncoderServiceProxy>> EncoderServiceProxy::FindService(ara::core::InstanceSpecifier specifier) {
                std::vector<std::unique_ptr<proxy::EncoderServiceProxy>> proxies;
                std::unique_ptr proxy = std::make_unique<proxy::EncoderServiceProxy>();

                proxy->encoderProxyApp = vsomeip::runtime::get()->create_application("encoderProxy");
                proxies.push_back(std::move(proxy));

                return proxies;
            }

            void EncoderServiceProxy::subscribeEncoderEvent(int queue_size) {
                // Subscribe Logic
                // client->startClient();
                std::cout << "Subscribed to EncoderEvent with queue size: " << queue_size << std::endl;
                someipThread = std::thread(&EncoderServiceProxy::runSomeip, this);
                subscriberThread = std::thread(&EncoderServiceProxy::subscriber, this);
            }

            void EncoderServiceProxy::on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available) {
                std::cout << "CLIENT: Service ["
                        << std::setw(4) << std::setfill('0') << std::hex << _service << "." << _instance
                        << "] is "
                        << (_is_available ? "available." : "NOT available.")
                        << std::endl;
                condition.notify_one();
            }

            void EncoderServiceProxy::on_message(const std::shared_ptr<vsomeip::message> &_response) {
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

            void EncoderServiceProxy::runSomeip() {
                this->encoderProxyApp->init();
                this->encoderProxyApp->register_availability_handler(
                    SERVICE_ID, INSTANCE_ID,
                    std::bind(&EncoderServiceProxy::on_availability, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)
                );
                this->encoderProxyApp->request_service(SERVICE_ID, INSTANCE_ID);
                this->encoderProxyApp->register_message_handler(
                    vsomeip::ANY_SERVICE, vsomeip::ANY_INSTANCE, vsomeip::ANY_METHOD, 
                    std::bind(&EncoderServiceProxy::on_message, this, std::placeholders::_1));
                this->encoderProxyApp->start();
            }

            void EncoderServiceProxy::subscriber() {
                std::unique_lock<std::mutex> its_lock(mutex);
                condition.wait(its_lock);

                std::set<vsomeip::eventgroup_t> its_groups;
                its_groups.insert(EVENTGROUP_ID);
                encoderProxyApp->request_event(SERVICE_ID, INSTANCE_ID, EVENT_ID, its_groups);
                encoderProxyApp->subscribe(SERVICE_ID, INSTANCE_ID, EVENTGROUP_ID);
            }

            void EncoderServiceProxy::setEncoderEventReceiveHandler(std::function<void()>& handler) {
                // Set Handler
                std::cout << "EncoderEvent receive handler set." << std::endl;
                // client->setCallback(handler);
            }

            void EncoderServiceProxy::getNewSamples(std::function<void(std::shared_ptr<ara::com::proxy::events::EncoderEvent::EncoderSampleType>)> callback) {
                auto sample = std::make_shared<ara::com::proxy::events::EncoderEvent::EncoderSampleType>();
                // sample = client->fetchsample();
                // sample->active = true;
                // callback(sample);
            }
        }
    }
}
