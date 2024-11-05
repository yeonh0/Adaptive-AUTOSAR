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
            }

            std::vector<std::unique_ptr<proxy::EncoderServiceProxy>> EncoderServiceProxy::FindService(std::vector<std::string> specifier) {
                std::vector<std::unique_ptr<proxy::EncoderServiceProxy>> proxies;
                // Check specifier's size
                if (specifier.size() < 3) {
                    std::cerr << "Not Enough Specifier" << std::endl;
                    return proxies;
                }

                std::string IpAddress;
                std::string MulticastGroup;
                uint16_t Port;
                
                try {
                    IpAddress = specifier[0];
                    MulticastGroup = specifier[1];
                    Port = static_cast<uint16_t>(std::stoi(specifier[2]));
                } 
                catch (const std::exception &e) {
                    std::cerr << "Invalid specifier format: " << e.what() << std::endl;
                    return proxies;
                }

                uint16_t serviceId = 0x1234;
                int initialDelayMin = 10;
                int initialDelayMax = 50;

                // Wait Duration: (initialDelayMax + Summation of all the repetition phase delays & Apply high Nyquist–Shannon margin (make the duration twice longer)
                int WaitDuration = static_cast<int>((initialDelayMax + 30 * (std::pow(2, 3) - 1) + 100) * 10);

                // Create Poller, SDNetworkLayer, SDClient
                AsyncBsdSocketLib::Poller sdpoller;
                someip::sd::SdNetworkLayer mNetworkLayer(&sdpoller, IpAddress, MulticastGroup, Port);
                ara::com::someip::sd::SomeIpSdClient sdClient(&mNetworkLayer, serviceId, initialDelayMin, initialDelayMax, 200, 2);

                // Service Discovery Start
                std::cout << "Start Service Discovery Client .." << std::endl;
                sdClient.Start();

                bool sdsuccess = sdClient.TryWaitUntiServiceOffered(WaitDuration);

                std::string _ipAddress;
                uint16_t _port;

                // Receive SD Message - during 2 sec
                auto start = std::chrono::steady_clock::now();
                std::cout << "Check SD Message From SD Server .." << std::endl;

                while(true) {
                    mNetworkLayer.onReceive();
                    // Success to Find SD Server
                    if(sdClient.TryGetOfferedEndpoint(_ipAddress, _port)) {
                        std::cout << "Find Service - End Discovery Client" << std::endl;
                        // Create Proxy Instance
                        std::unique_ptr<proxy::EncoderServiceProxy> proxy = std::make_unique<proxy::EncoderServiceProxy>();
                        proxies.push_back(std::move(proxy));
                        break;
                    }
                    else {
                        auto now = std::chrono::steady_clock::now();
                        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
                        if (elapsed >= 2) {
                            std::cout << "Can't Find Service (Time out) - End Discovery Client" << std::endl;
                            break;
                        }
                    }
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
                // Stop SD Client
                sdClient.Stop();
                return proxies;
            }

            void EncoderServiceProxy::subscribeEncoderEvent(int queue_size) {
                // Subscribe Logic
                // client->startClient();
                std::cout << "Subscribed to EncoderEvent with queue size: " << queue_size << std::endl;
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
