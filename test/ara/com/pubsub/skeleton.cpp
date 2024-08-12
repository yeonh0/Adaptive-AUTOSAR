#include <future>
#include <atomic>
#include <iostream>
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
                  sdIP(172, 24, 125, 198),
                  SDServer(&mNetworkLayer, cServiceId, cInstanceId, 
                  cMajorVersion, cMinorVersion, nicIpAddress, 33333, 
                  cInitialDelayMin, cInitialDelayMax, cRepetitionBaseDelay, 
                  cCycleOfferDelay, cRepetitionMax),
                  stopAsyncTask(false) {
            }

            Skeleton::~Skeleton() {
                Stop();
            }
            
            void Skeleton::init() {
                SDServer.Start();
                this->running = true;
                std::cout << "SomeIpPublisher started..." << std::endl;

                future = std::async(std::launch::async, [&]() {
                    while(!stopAsyncTask.load()) {
                        mNetworkLayer.onReceive();
                        std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    }
                });
            }

            void Skeleton::Stop() {
                if (running) {
                    running = false;
                    std::cout << "SomeIpPublisher stopped." << std::endl;
                }
                stopAsyncTask.store(true);
                SDServer.Stop();
                if (future.valid()) {
                    future.wait();
                }
            }

            void Skeleton::OfferService()
            {
                if (!running)
                {
                    throw std::runtime_error("Publisher is not running.");
                }

                // Ensure there's enough time for init to complete
                std::this_thread::sleep_for(std::chrono::seconds(2));

                while(1) {
                    mNetworkLayer.Send()
                }
            }
        }
    }
}