#include "skeleton.h"

namespace ara
{
    namespace com
    {
        namespace pubsub
        {
            EncoderServiceSkeleton::EncoderServiceSkeleton(ara::core::InstanceSpecifier instanceIds)
            {
                // create vsomeip application
                app = vsomeip::runtime::get()->create_application("EncoderServiceSkeleton");
                app->init();
            }

            EncoderServiceSkeleton::~EncoderServiceSkeleton() {
                StopOfferService();
                if (someipThread.joinable()) {
                    someipThread.join();
                }
            }
            
            void EncoderServiceSkeleton::init() {
                // vsomeip application init
                const vsomeip::byte_t its_data[] = { 0x10 };
                payload = vsomeip::runtime::get()->create_payload();
                payload->set_data(its_data, sizeof(its_data));
            }

            ara::core::Result<void> EncoderServiceSkeleton::OfferService()
            {
                someipThread = std::thread(&EncoderServiceSkeleton::runSomeip, this);

                return ara::core::Result<void>::FromValue();
            }

            void EncoderServiceSkeleton::StopOfferService() {
                app->stop();
            }

            void EncoderServiceSkeleton::runSomeip() {
                its_groups.insert(EVENTGROUP_ID);
                app->offer_event(SERVICE_ID, INSTANCE_ID, EVENT_ID, its_groups);
                app->notify(SERVICE_ID, INSTANCE_ID, EVENT_ID, payload);
                app->start();
            }
        }
    }
}