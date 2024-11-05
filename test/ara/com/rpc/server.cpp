#include "skeleton.h"

using namespace ara::com::rpc;

int main(int argc, char **argv) {

    // --- 1. Define instance identifiers for ROS2 and SOME/IP bindings
    ara::core::InstanceSpecifier Ros2InstanceId("ROS2_Instance");
    ara::core::InstanceSpecifier SomeIpInstanceId("SOMEIP_Instance");

    // --- 2. Create an InstanceIdentifierContainer and add the identifiers to it
    std::vector <ara::core::InstanceSpecifier> instanceIds;
    instanceIds.push_back(Ros2InstanceId);
    instanceIds.push_back(SomeIpInstanceId);

    // --- 3. Use the container to create a RadarServiceSkeleton instance
    mySkeleton skeleton(instanceIds);

    // --- 4. Start Offer Service ---
    skeleton.OfferService();


    // --- 3. Main loop. Do nothing ---
    while(1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}