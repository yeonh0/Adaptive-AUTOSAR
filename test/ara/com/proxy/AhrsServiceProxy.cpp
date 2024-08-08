#include "AhrsServiceProxy.h"

namespace ara
{
    namespace com
    {
        namespace proxy
        {
            AhrsServiceProxy::AhrsServiceProxy()
            {
                client = std::make_shared<ara::com::ros2::pubsub::ROS2PubSubClient>();
            }

            AhrsServiceProxy::~AhrsServiceProxy()
            {
            }

            std::vector<std::unique_ptr<proxy::AhrsServiceProxy>> AhrsServiceProxy::FindService() {
                std::vector<std::unique_ptr<proxy::AhrsServiceProxy>> proxies;
                std::unique_ptr proxy = std::make_unique<proxy::AhrsServiceProxy>();
                proxies.push_back(std::move(proxy));
                return proxies;
            }

            void AhrsServiceProxy::subscribeIMUEvent(int queue_size) {
                // Subscribe Logic
                client->startClient();
                std::cout << "Subscribed to IMUEvent with queue size: " << queue_size << std::endl;
            }

            void AhrsServiceProxy::setIMUEventReceiveHandler(std::function<void()>& handler) {
                // Set Handler
                std::cout << "IMUEvent receive handler set." << std::endl;
                client->setCallback(handler);
            }

            void AhrsServiceProxy::getNewSamples(std::function<void(std::shared_ptr<ara::com::proxy::events::IMUEvent::IMUSampleType>)> callback) {
                auto sample = std::make_shared<ara::com::proxy::events::IMUEvent::IMUSampleType>();
                sample = client->fetchsample();
                sample->active = true;
                callback(sample);
            }
        }
    }
}
