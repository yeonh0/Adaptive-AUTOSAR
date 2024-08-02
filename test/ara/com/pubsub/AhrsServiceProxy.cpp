#include "AhrsServiceProxy.h"

namespace ara
{
    namespace com
    {
        namespace pubsub
        {
            AhrsServiceProxy::AhrsServiceProxy()
            {
                client = std::make_shared<ara::com::ros2::pubsub::ROS2PubSubClient>();
            }

            AhrsServiceProxy::~AhrsServiceProxy()
            {
            }

            void AhrsServiceProxy::SubscribeIMUEvent(int queue_size) {
                // Subscribe Logic
                client->startClient();
                std::cout << "Subscribed to IMUEvent with queue size: " << queue_size << std::endl;
            }

            void AhrsServiceProxy::SetIMUEventReceiveHandler(std::function<void()>& handler) {
                // Set Handler
                std::cout << "IMUEvent receive handler set." << std::endl;
                client->setCallback(handler);
            }

            void AhrsServiceProxy::GetNewSamples(std::function<void(std::shared_ptr<ara::com::proxy::events::BrakeEvent::SampleType>)> callback) {
                auto sample = std::make_shared<ara::com::proxy::events::BrakeEvent::SampleType>();
                sample = client->fetchsample();
                sample->active = true;
                callback(sample);
            }
        }
    }
}
