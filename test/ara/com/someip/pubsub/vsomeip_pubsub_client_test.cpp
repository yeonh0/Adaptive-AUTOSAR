#include "../../../../../src/ara/com/someip/pubsub/vsomeip_pubsub_client.h"

using namespace ara::com::someip::pubsub;

#define SERVICE_ID 0x1234
#define INSTANCE_ID 0x5678
#define EVENTGROUP_ID 0x4465
#define EVENT_ID 0x8778

std::shared_ptr <VsomeIpPubSubClient> client = std::make_shared <VsomeIpPubSubClient>("poseEstimation");

int main() {
    client->init();
    client->requestService(SERVICE_ID, INSTANCE_ID);
    client->makeHandler();
    client->Subscribe(SERVICE_ID, INSTANCE_ID, EVENT_ID, EVENTGROUP_ID);
    client->dispatch();

    return 0;
}