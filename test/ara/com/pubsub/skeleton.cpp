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
                SDServer.Start();
                this->running = true;
                std::cout << "SomeIpPublisher started..." << std::endl;
            }

            void Skeleton::Stop() {
                if (running) {
                    running = false;
                    std::cout << "SomeIpPublisher stopped." << std::endl;
                }
                SDServer.Stop();
            }

            void Skeleton::OfferService() {
                
            }

            void Skeleton::Publish(const std::vector<uint8_t> &data)
            {
                if (!running)
                {
                    throw std::runtime_error("Publisher is not running.");
                }
                mNetworkLayer.onReceive();
            }
        }
    }
}
