########################################################################
#
# Requirements and dependencies:

cmake_minimum_required(VERSION 3.14)
project(Adaptive_Platform)

# This AUTOSAR Adaptive Platform requires C++17
set(CMAKE_CXX_STANDARD 17)
# Enable 'rdyamic' switch to export the executable's symbols for debugging
set(CMAKE_ENABLE_EXPORTS 1)

include(FetchContent)

# Fetching Async-BSD-Socket-Lib for network abstraction
FetchContent_Declare(
  Async-BSD-Socket-Lib
  URL https://github.com/langroodi/Async-BSD-Socket-Lib/archive/8c84da8f4b5e7552b41a54c92acb0b4565d07024.zip
)

FetchContent_MakeAvailable(
  Async-BSD-Socket-Lib
)

########################################################################
#
# Find ROS2

if(NOT DEFINED ENV{AMENT_PREFIX_PATH})
  set(ENV{AMENT_PREFIX_PATH} "/opt/ros/humble")
endif()
list(APPEND CMAKE_PREFIX_PATH $ENV{AMENT_PREFIX_PATH})

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(rcl_interfaces REQUIRED)
find_package(rosidl_typesupport_cpp REQUIRED)

include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
  ${std_srvs_INCLUDE_DIRS}
  ${rcl_interfaces_INCLUDE_DIRS}
  ${rosidl_typesupport_cpp_INCLUDE_DIRS}
)

########################################################################
#
# Source Directories:

set(source_dir
  "${CMAKE_SOURCE_DIR}/src")

set(source_ara_core_dir
  "${CMAKE_SOURCE_DIR}/src/ara/core")

set(source_ara_log_dir
  "${CMAKE_SOURCE_DIR}/src/ara/log")

set(source_ara_log_sink_dir
  "${CMAKE_SOURCE_DIR}/src/ara/log/sink")

set(source_ara_com_cg_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/cg")

set(source_ara_com_e2e_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/e2e")

set(source_ara_com_helper_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/helper")

set(source_ara_com_option_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/option")  

set(source_ara_com_entry_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/entry")

set(source_ara_com_someip_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/someip")

set(source_ara_com_someip_rpc_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/someip/rpc")

set(source_ara_com_someip_sd_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/someip/sd")

set(source_ara_com_someip_sd_fsm_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/someip/sd/fsm")

set(source_ara_com_someip_pubsub_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/someip/pubsub")

set(source_ara_com_someip_pubsub_fsm_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/someip/pubsub/fsm")

set(source_ara_com_ros2_pubsub_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/ros2/pubsub")

set(source_ara_com_ros2_rpc_dir
  "${CMAKE_SOURCE_DIR}/src/ara/com/ros2/rpc")

# Test Directories:

set(test_ara_log_dir
  "${CMAKE_SOURCE_DIR}/test/ara/log")

set(test_ara_com_e2e_dir
  "${CMAKE_SOURCE_DIR}/test/ara/com/e2e")

set(test_ara_com_entry_dir
  "${CMAKE_SOURCE_DIR}/test/ara/com/entry")

set(test_ara_com_helper_dir
  "${CMAKE_SOURCE_DIR}/test/ara/com/helper")

set(test_ara_com_option_dir
  "${CMAKE_SOURCE_DIR}/test/ara/com/option")

set(test_ara_com_someip_pubsub_dir
  "${CMAKE_SOURCE_DIR}/test/ara/com/someip/pubsub")

set(test_ara_com_someip_pubsub_fsm_dir
  "${CMAKE_SOURCE_DIR}/test/ara/com/someip/pubsub/fsm")

set(test_ara_com_someip_rpc_dir
  "${CMAKE_SOURCE_DIR}/test/ara/com/someip/rpc")

set(test_ara_com_someip_sd_dir
  "${CMAKE_SOURCE_DIR}/test/ara/com/someip/sd")

set(test_ara_com_someip_sd_fsm_dir
  "${CMAKE_SOURCE_DIR}/test/ara/com/someip/sd/fsm")

set(test_ara_com_pubsub_dir
  "${CMAKE_SOURCE_DIR}/test/ara/com/pubsub")

set(test_ara_com_rpc_dir
  "${CMAKE_SOURCE_DIR}/test/ara/com/rpc")

########################################################################

add_library(
  ara_core
  ${source_ara_core_dir}/optional.h
  ${source_ara_core_dir}/result.h
  ${source_ara_core_dir}/error_domain.h
  ${source_ara_core_dir}/error_code.h
  ${source_ara_core_dir}/error_code.cpp
  ${source_ara_core_dir}/instance_specifier.h
  ${source_ara_core_dir}/instance_specifier.cpp
)

add_library(
  ara_log
  ${source_ara_log_dir}/argument.h
  ${source_ara_log_dir}/log_stream.h
  ${source_ara_log_dir}/log_stream.cpp
  ${source_ara_log_dir}/logger.h
  ${source_ara_log_dir}/logger.cpp
  ${source_ara_log_dir}/logging_framework.h
  ${source_ara_log_dir}/logging_framework.cpp
  ${source_ara_log_sink_dir}/console_log_sink.h
  ${source_ara_log_sink_dir}/console_log_sink.cpp
  ${source_ara_log_sink_dir}/file_log_sink.h
  ${source_ara_log_sink_dir}/file_log_sink.cpp
  ${source_ara_log_sink_dir}/log_sink.h
  ${source_ara_log_sink_dir}/log_sink.cpp
)

add_library(
  ara_com
  ${source_ara_com_cg_dir}/communication_group_client.h
  ${source_ara_com_cg_dir}/communication_group_server.h
  ${source_ara_com_e2e_dir}/profile11.h
  ${source_ara_com_e2e_dir}/profile11.cpp
  ${source_ara_com_helper_dir}/payload_helper.h
  ${source_ara_com_helper_dir}/payload_helper.cpp
  ${source_ara_com_helper_dir}/ipv4_address.h
  ${source_ara_com_helper_dir}/ipv4_address.cpp
  ${source_ara_com_helper_dir}/abstract_state_machine.h
  ${source_ara_com_helper_dir}/machine_state.h
  ${source_ara_com_helper_dir}/finite_state_machine.h
  ${source_ara_com_helper_dir}/ttl_timer.h
  ${source_ara_com_helper_dir}/ttl_timer.cpp
  ${source_ara_com_helper_dir}/network_layer.h
  ${source_ara_com_helper_dir}/concurrent_queue.h
  ${source_ara_com_entry_dir}/entry.h
  ${source_ara_com_entry_dir}/entry.cpp
  ${source_ara_com_entry_dir}/eventgroup_entry.h
  ${source_ara_com_entry_dir}/eventgroup_entry.cpp
  ${source_ara_com_entry_dir}/service_entry.h
  ${source_ara_com_entry_dir}/service_entry.cpp
  ${source_ara_com_entry_dir}/entry_deserializer.h
  ${source_ara_com_entry_dir}/entry_deserializer.cpp
  ${source_ara_com_option_dir}/option.h
  ${source_ara_com_option_dir}/option.cpp
  ${source_ara_com_option_dir}/ipv4_endpoint_option.h
  ${source_ara_com_option_dir}/ipv4_endpoint_option.cpp
  ${source_ara_com_option_dir}/loadbalancing_option.h
  ${source_ara_com_option_dir}/loadbalancing_option.cpp
  ${source_ara_com_option_dir}/option_deserializer.h
  ${source_ara_com_option_dir}/option_deserializer.cpp
  ${source_ara_com_someip_dir}/someip_message.h
  ${source_ara_com_someip_dir}/someip_message.cpp
  ${source_ara_com_someip_rpc_dir}/someip_rpc_message.h
  ${source_ara_com_someip_rpc_dir}/someip_rpc_message.cpp
  ${source_ara_com_someip_rpc_dir}/rpc_server.h
  ${source_ara_com_someip_rpc_dir}/rpc_server.cpp
  ${source_ara_com_someip_rpc_dir}/socket_rpc_server.h
  ${source_ara_com_someip_rpc_dir}/socket_rpc_server.cpp
  ${source_ara_com_someip_rpc_dir}/rpc_client.h
  ${source_ara_com_someip_rpc_dir}/rpc_client.cpp
  ${source_ara_com_someip_rpc_dir}/socket_rpc_client.h
  ${source_ara_com_someip_rpc_dir}/socket_rpc_client.cpp

  # SOMEIP RPC
  ${source_ara_com_someip_rpc_dir}/someip_rpc_client.h
  ${source_ara_com_someip_rpc_dir}/someip_rpc_client.cpp
  ${source_ara_com_someip_rpc_dir}/someip_rpc_server.h
  ${source_ara_com_someip_rpc_dir}/someip_rpc_server.cpp

  # ROS2 RPC
  ${source_ara_com_ros2_rpc_dir}/ros2_rpc_server.h
  ${source_ara_com_ros2_rpc_dir}/ros2_rpc_server.cpp

  ${source_ara_com_someip_pubsub_dir}/someip_pubsub_server.h
  ${source_ara_com_someip_pubsub_dir}/someip_pubsub_server.cpp
  ${source_ara_com_someip_pubsub_dir}/someip_pubsub_client.h
  ${source_ara_com_someip_pubsub_dir}/someip_pubsub_client.cpp
  ${source_ara_com_someip_pubsub_dir}/someip_pubsub_message.h
  ${source_ara_com_someip_pubsub_dir}/someip_pubsub_message.cpp
   # ROS2 PUBSUB
  ${source_ara_com_ros2_pubsub_dir}/ros2_pubsub_server.h
  ${source_ara_com_ros2_pubsub_dir}/ros2_pubsub_server.cpp

  ${source_ara_com_someip_pubsub_fsm_dir}/service_down_state.h
  ${source_ara_com_someip_pubsub_fsm_dir}/service_down_state.cpp
  ${source_ara_com_someip_pubsub_fsm_dir}/notsubscribed_state.h
  ${source_ara_com_someip_pubsub_fsm_dir}/notsubscribed_state.cpp
  ${source_ara_com_someip_pubsub_fsm_dir}/subscribed_state.h
  ${source_ara_com_someip_pubsub_fsm_dir}/subscribed_state.cpp
  ${source_ara_com_someip_sd_dir}/someip_sd_agent.h
  ${source_ara_com_someip_sd_dir}/someip_sd_message.h
  ${source_ara_com_someip_sd_dir}/someip_sd_message.cpp
  ${source_ara_com_someip_sd_dir}/someip_sd_server.h
  ${source_ara_com_someip_sd_dir}/someip_sd_server.cpp
  ${source_ara_com_someip_sd_dir}/someip_sd_client.h
  ${source_ara_com_someip_sd_dir}/someip_sd_client.cpp
  ${source_ara_com_someip_sd_dir}/sd_network_layer.h
  ${source_ara_com_someip_sd_dir}/sd_network_layer.cpp
  ${source_ara_com_someip_sd_fsm_dir}/timer_set_state.h
  ${source_ara_com_someip_sd_fsm_dir}/client_service_state.h
  ${source_ara_com_someip_sd_fsm_dir}/notready_state.h
  ${source_ara_com_someip_sd_fsm_dir}/notready_state.cpp
  ${source_ara_com_someip_sd_fsm_dir}/initial_wait_state.h
  ${source_ara_com_someip_sd_fsm_dir}/client_initial_wait_state.h
  ${source_ara_com_someip_sd_fsm_dir}/client_initial_wait_state.cpp
  ${source_ara_com_someip_sd_fsm_dir}/repetition_state.h
  ${source_ara_com_someip_sd_fsm_dir}/client_repetition_state.h
  ${source_ara_com_someip_sd_fsm_dir}/client_repetition_state.cpp
  ${source_ara_com_someip_sd_fsm_dir}/main_state.h
  ${source_ara_com_someip_sd_fsm_dir}/main_state.cpp
  ${source_ara_com_someip_sd_fsm_dir}/stopped_state.h
  ${source_ara_com_someip_sd_fsm_dir}/stopped_state.cpp
  ${source_ara_com_someip_sd_fsm_dir}/service_notseen_state.h
  ${source_ara_com_someip_sd_fsm_dir}/service_notseen_state.cpp
  ${source_ara_com_someip_sd_fsm_dir}/service_ready_state.h
  ${source_ara_com_someip_sd_fsm_dir}/service_ready_state.cpp
  ${source_ara_com_someip_sd_fsm_dir}/service_seen_state.h
  ${source_ara_com_someip_sd_fsm_dir}/service_seen_state.cpp
)

target_link_libraries(
  ara_com
  async_bsd_socket_lib
  ${rclcpp_LIBRARIES}
  ${std_msgs_LIBRARIES}
  ${rcl_interfaces_LIBRARIES}
  ${std_srvs_LIBRARIES}
  ${rosidl_typesupport_cpp_LIBRARIES}
)

target_link_libraries(
  ara_log
  ara_core
  ara_com
)

add_executable(
  pubsubtest
  ${test_ara_com_pubsub_dir}/main.cpp
  ${test_ara_com_pubsub_dir}/pubsub_test.cpp
  ${test_ara_com_pubsub_dir}/pubsub_test.h
)

target_link_libraries(
  pubsubtest
  ara_log
)

ament_target_dependencies(
  pubsubtest
  rclcpp
  std_msgs
  rcl_interfaces
)

add_executable(
  rpc_server
  ${test_ara_com_rpc_dir}/server.cpp
  ${test_ara_com_rpc_dir}/skeleton.cpp
  ${test_ara_com_rpc_dir}/skeleton.h
)

target_link_libraries(
  rpc_server
  ara_log
)

add_executable(
  rpc_client
  ${test_ara_com_rpc_dir}/client.cpp
  ${test_ara_com_rpc_dir}/proxy.cpp
  ${test_ara_com_rpc_dir}/proxy.h
)

target_link_libraries(
  rpc_client
  ara_log
)

# target_link_libraries(
#   rpctest
#   rclcpp 
#   std_srvs
#   ara_log
#   rosidl_typesupport_cpp
# )