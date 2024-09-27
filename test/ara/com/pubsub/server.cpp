#include "skeleton.h"
using namespace ara::com;

int main(int argc, char** argv) {
    // read instanceId from commandline
    ara::core::InstanceSpecifier instanceIds(argv[1]);
    std::unique_ptr myEncoderService = std::make_unique<ara::com::pubsub::EncoderServiceSkeleton>(instanceIds);

    // do some service specific initialization here ....
    myEncoderService->init();

    // now service instance is ready -> make it visible/available
    myEncoderService->OfferService();

    // go into some wait state in main thread - waiting for AppExecMgr
    // signals or the like ....
    while(1) {
        std::cout << "Server Running ..." << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}