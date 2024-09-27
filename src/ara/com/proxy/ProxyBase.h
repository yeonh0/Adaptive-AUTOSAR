#ifndef RPROXYBASE_H
#define RPROXYBASE_H

#include "vsomeip/vsomeip.hpp"

namespace ara
{
    namespace com
    {
        namespace proxy
        {
            class ProxyBase
            {
            public:
                ProxyBase();
                ~ProxyBase();

            protected:
                void on_availability(vsomeip::service_t _service, vsomeip::instance_t _instance, bool _is_available);
                void on_message(const std::shared_ptr<vsomeip::message> &_request);

            private:
                std::shared_ptr< vsomeip::application > encoderProxyApp;
                uint16_t SERVICE_ID;
                uint16_t INSTANCE_ID;
                uint16_t EVENTGROUP_ID;
                uint16_t EVENT_ID;
                uint16_t METHOD_ID;
            };
        }
    }
}

#endif // PROXYBASE_H
