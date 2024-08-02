#include "AhrsServiceProxy.h"

using namespace ara::com::pubsub;
using Float64Array3 = std::array<double, 3>;

// AHRS Proxy
std::unique_ptr<AhrsServiceProxy> myAhrsProxy;

// IMU Event Sample Queue
//using SamplePtr = std::shared_ptr<const proxy::events::BrakeEvent::SampleType>;
//std::deque<SamplePtr> lastNActiveSamples;
std::deque<std::shared_ptr<const ara::com::proxy::events::BrakeEvent::SampleType>> lastNActiveSamples;

// Event Handler Function
void processLastIMUEvents(std::deque<std::shared_ptr<const ara::com::proxy::events::BrakeEvent::SampleType>>& samples) {
    if (!samples.empty()) {
        //std::cout << samples[0]->angular_velocity[0] << " " << samples[0]->angular_velocity[1] << " " << samples[0]->angular_velocity[2] << std::endl;
        auto samplePtr = samples.front();
        samples.pop_front();

        Float64Array3 orientation = samplePtr->orientation;
        Float64Array3 angular_velocity = samplePtr->angular_velocity;
        Float64Array3 linear_acceleration = samplePtr->linear_acceleration;

        std::cout << "orientation: " << orientation[0] << " -- " << orientation[1] << " -- " << orientation[2] << std::endl;
        std::cout << "angular_velocity: " << angular_velocity[0] << " -- " << angular_velocity[1] << " -- " << angular_velocity[2] << std::endl;
        std::cout << "linear_acceleration: " << linear_acceleration[0] << " -- " << linear_acceleration[1] << " -- " << linear_acceleration[2] << std::endl;
        std::cout << '\n';
    }
}

// Process Event
void handleIMUEventReception() {
    myAhrsProxy->GetNewSamples(
    [](std::shared_ptr<ara::com::proxy::events::BrakeEvent::SampleType> samplePtr) {
        if(samplePtr->active) {
            lastNActiveSamples.push_back(std::move(samplePtr));
            if(lastNActiveSamples.size() > 10) 
                lastNActiveSamples.pop_front();
        }
    });
    processLastIMUEvents(lastNActiveSamples);
}

int main(int argc, char** argv) {
    // Find Service: Get Handlers of Service Instance
    bool foundServiceInstance = true;
    // If Find Instance Handler
    if(foundServiceInstance) {
        // Create Proxy: Using Service Instance Handler
        myAhrsProxy = std::make_unique<AhrsServiceProxy>();

        // Subscribe "IMU Event" (assync)
        myAhrsProxy->SubscribeIMUEvent(10);
        
        // Register Event Callback Handler
        std::function<void()> handler = handleIMUEventReception;
        myAhrsProxy->SetIMUEventReceiveHandler(handler);

        // Loop (Main Thread)
        while(1) {

        }
    }

    return 0;
}
