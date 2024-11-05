#include "../proxy/AhrsServiceProxy.h"
#include "../proxy/EncoderServiceProxy.h"

using namespace ara::com;
using Float64Array3 = std::array<double, 3>;

// Proxy
std::unique_ptr<proxy::EncoderServiceProxy> myEncoderProxy;
std::unique_ptr<proxy::AhrsServiceProxy> myAhrsProxy;

// IMU Event Sample Queue
std::deque<std::shared_ptr<const ara::com::proxy::events::EncoderEvent::EncoderSampleType>> EncoderlastNActiveSamples;
std::deque<std::shared_ptr<const ara::com::proxy::events::IMUEvent::IMUSampleType>> IMUlastNActiveSamples;

// Eventimu Function
void processLastIMUEvents(std::deque<std::shared_ptr<const ara::com::proxy::events::IMUEvent::IMUSampleType>>& samples) {
    if (!samples.empty()) {
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

void processLastEncoderEvents(std::deque<std::shared_ptr<const ara::com::proxy::events::EncoderEvent::EncoderSampleType>>& samples) {
    if (!samples.empty()) {
        auto samplePtr = samples.front();
        samples.pop_front();

        Float64Array3 _value = samplePtr->encoder_value;

        std::cout << "Encoder: " << _value[0] << " -- " << _value[1] << " -- " << _value[2] << std::endl;
        std::cout << '\n';
    }
}

// Process Event
void handleIMUEventReception() {
    myAhrsProxy->getNewSamples(
    [](std::shared_ptr<ara::com::proxy::events::IMUEvent::IMUSampleType> samplePtr) {
        if(samplePtr->active) {
            IMUlastNActiveSamples.push_back(std::move(samplePtr));
            if(IMUlastNActiveSamples.size() > 10)
                IMUlastNActiveSamples.pop_front();
        }
    });
    processLastIMUEvents(IMUlastNActiveSamples);
}

void handleEncoderEventReception() {
    myEncoderProxy->getNewSamples(
    [](std::shared_ptr<ara::com::proxy::events::EncoderEvent::EncoderSampleType> samplePtr) {
        EncoderlastNActiveSamples.push_back(std::move(samplePtr));
        if(EncoderlastNActiveSamples.size() > 10) 
            EncoderlastNActiveSamples.pop_front();
    });
    processLastEncoderEvents(EncoderlastNActiveSamples);
}

int main(int argc, char** argv) {
    /* Instance Specifier from model */
    std::vector<std::string> encoder_instspec{"172.24.125.198", "225.255.240.0", "33333"};

    auto encoder_handles = proxy::EncoderServiceProxy::FindService(encoder_instspec);
    auto ahrs_handles = proxy::AhrsServiceProxy::FindService();

    if(!encoder_handles.empty() || !ahrs_handles.empty()) {
        myEncoderProxy = std::move(encoder_handles[0]);
        myAhrsProxy = std::move(ahrs_handles[0]);

        myEncoderProxy->subscribeEncoderEvent(10);
        myAhrsProxy->subscribeIMUEvent(10);

        // Register Event Callback Handler
        std::function<void()> EncoderHandler = handleEncoderEventReception;
        myEncoderProxy->setEncoderEventReceiveHandler(EncoderHandler);

        std::function<void()> IMUHandler = handleIMUEventReception;
        myAhrsProxy->setIMUEventReceiveHandler(IMUHandler);
    }

    while(1){
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    
    return 0;
}
