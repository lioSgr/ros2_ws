cmake_minimum_required(VERSION 3.8)
project(cpp_pkg_with_custom_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tutorial_interfaces REQUIRED)                      # CHANGE

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp tutorial_interfaces)    # CHANGE

add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp tutorial_interfaces)  # CHANGE

add_executable(server src/add_three_ints_server.cpp)
ament_target_dependencies(server
                          rclcpp
                          tutorial_interfaces)                      # CHANGE

add_executable(client src/add_three_ints_client.cpp)
ament_target_dependencies(client
                          rclcpp
                          tutorial_interfaces)                      # CHANGE

install(TARGETS
        talker
        listener
        server
        client
        DESTINATION lib/${PROJECT_NAME})

ament_package()