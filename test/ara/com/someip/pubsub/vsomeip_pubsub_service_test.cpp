#include "../../../../../src/ara/com/someip/pubsub/vsomeip_pubsub_service.h"
#include <vector>
using namespace ara::com::someip::pubsub;

#define SERVICE_ID 0x1234
#define INSTANCE_ID 0x5678
#define METHOD_ID 0x0421
#define EVENTGROUP_ID 0x4465
#define EVENT_ID 0x8778

std::shared_ptr<VsomeIpPubSubServer> server = std::make_shared<VsomeIpPubSubServer>("ImuServer", SERVICE_ID, INSTANCE_ID);
std::shared_ptr<vsomeip::payload> payload;

int main() {
    const vsomeip::byte_t its_data[] = { 0x10, 0x11, 0x12, 0x13 };
    std::shared_ptr<vsomeip::payload>payload_ = vsomeip::runtime::get()->create_payload();
    payload_->set_data(its_data, sizeof(its_data));

    std::set<vsomeip::eventgroup_t> its_groups;
    its_groups.insert(EVENTGROUP_ID);

    server->init();
    server->offerService(SERVICE_ID, INSTANCE_ID);
    
    server->registerEvent(SERVICE_ID, INSTANCE_ID, EVENT_ID, its_groups);
    server->sendEvent(SERVICE_ID, INSTANCE_ID, EVENT_ID, payload_, 1000);

    server->dispatch();

    return 0;
}