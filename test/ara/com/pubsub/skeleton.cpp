#include "skeleton.h"

namespace ara
{
    namespace com
    {
        namespace pubsub
        {
            Skeleton::Skeleton(
                AsyncBsdSocketLib::Poller *poller, 
                const std::string &nicIpAddress,
                const std::string &multicastGroup,
                uint16_t port)
                : mPoller{poller},
                  mNetworkLayer(mPoller, nicIpAddress, multicastGroup, port),
                  running(false),
                  sdIP("172.24.125.198"),
                  SDServer(&mNetworkLayer, cServiceId, cInstanceId, 
                  cMajorVersion, cMinorVersion, sdIP, 33333, 
                  cInitialDelayMin, cInitialDelayMax, cRepetitionBaseDelay, 
                  cCycleOfferDelay, cRepetitionMax) {
            }

            Skeleton::~Skeleton() {
                Stop();
            }
            
            void Skeleton::Start() {
                this->running = true;
                std::cout << "SomeIpPublisher started..." << std::endl;
            }

            void Skeleton::Stop() {
                if (running)
                    {
                        running = false;
                        std::cout << "SomeIpPublisher stopped." << std::endl;
                    }
            }

            void Skeleton::OfferService() {
                
            }

            void Skeleton::Publish(const std::vector<uint8_t> &data)
            {
                if (!running)
                {
                    throw std::runtime_error("Publisher is not running.");
                }

                std::cout << "Publishing data..." << std::endl;

                someip::sd::SomeIpSdMessage message;

                auto serviceEntry1 = entry::ServiceEntry::CreateOfferServiceEntry(12,123,124,34,1235);
                auto serviceEntry2 = entry::ServiceEntry::CreateOfferServiceEntry(0x1234,0x345,0x00,0x00,1235);
                message.AddEntry(std::move(serviceEntry1));
                message.AddEntry(std::move(serviceEntry2));

                mNetworkLayer.Send(message);
                mNetworkLayer.onSend();
                mNetworkLayer.onReceive();
            }
        }
    }
}
