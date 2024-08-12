#include "skeleton.h"

int main() {
    AsyncBsdSocketLib::Poller poller;
    std::unique_ptr testsk = std::make_unique<ara::com::pubsub::Skeleton>(&poller, "172.24.125.198", "225.255.240.0", 33333);
    
    testsk->init();

    testsk->OfferService();

    testsk->Stop();
}