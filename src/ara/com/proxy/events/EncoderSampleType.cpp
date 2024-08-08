#include <array>

using Float64Array3 = std::array<double, 3>;

namespace ara 
{
  namespace com 
  {
    namespace proxy 
    {
      namespace events 
      {
        struct EncoderEvent 
        {
          struct EncoderSampleType 
          {
            Float64Array3 encoder_value;

            bool active;
          };
        };
      } // namespace events
    } // namespace proxy
  }
}
