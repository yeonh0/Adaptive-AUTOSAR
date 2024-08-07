#include <array>
#include <rclcpp/rclcpp.hpp>

using Float64Array3 = std::array<double, 3>;

namespace ara
{
    namespace com
    {
        namespace proxy
        {
            namespace events
            {
                struct IMUEvent
                {
                    struct IMUSampleType
                    {
                        Float64Array3 orientation;
                        std::array<double, 9> orientation_covariance;

                        Float64Array3 angular_velocity;
                        std::array<double, 9> angular_velocity_covariance;

                        Float64Array3 linear_acceleration;
                        std::array<double, 9> linear_acceleration_covariance;

                        rclcpp::Time timestamp;

                        bool active;
                    };
                };
            } // namespace events
        }     // namespace proxy
    }         // namespace com
} // namespace ara
