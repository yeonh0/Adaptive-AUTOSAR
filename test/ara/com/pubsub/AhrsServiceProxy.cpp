#include "AhrsServiceProxy.h"

namespace ara
{
    namespace com
    {
        namespace pubsub
        {
            AhrsServiceProxy::AhrsServiceProxy(const std::string &nicIpAddress, const std::string &multicastGroup, uint16_t port)
            : poller{}, mNetworkLayer(&poller, nicIpAddress, multicastGroup, port), 
            sdClient(&mNetworkLayer, serviceId, initialDelayMin, initialDelayMax, 200, 2), 
            WaitDuration{static_cast<int>(
                // Initial wait phase delay
                (initialDelayMax +
                // Summation of all the repetition phase delays
                30 * (std::pow(2, 3) - 1) +
                // Main main first cycle delay
                100) *
                // Apply high Nyquist–Shannon margin (make the duration twice longer)
                10)}
            {
                client = std::make_shared<ara::com::ros2::pubsub::ROS2PubSubClient>();
            }

            AhrsServiceProxy::~AhrsServiceProxy()
            {
            }

            void AhrsServiceProxy::findService() {
                sdClient.Start();
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

            void AhrsServiceProxy::getNewSamples(std::function<void(std::shared_ptr<ara::com::proxy::events::BrakeEvent::SampleType>)> callback) {
                auto sample = std::make_shared<ara::com::proxy::events::BrakeEvent::SampleType>();
                sample = client->fetchsample();
                sample->active = true;
                callback(sample);
            }

            void AhrsServiceProxy::HI() {
                std::cout << "waitduration: " << WaitDuration << std::endl;
                sdClient.TryWaitUntiServiceOffered(2500);
                mNetworkLayer.onReceive();

                std::string _ipAddress;
                uint16_t _port;
                std::cout << sdClient.TryGetOfferedEndpoint(_ipAddress, _port) << std::endl;
                std::cout << "ip, client : " << _ipAddress << ", " << _port << std::endl;
            }
        }
    }
}
