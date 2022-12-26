cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(talker src/publisher_member_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)
  
  install(TARGETS
    talker
    listener
    DESTINATION lib/${PROJECT_NAME})

ament_package()
