/**
 * @file publisher_member_function.cpp
 * @author lio (lioSgr@126.com)
 * @brief 创建发布者节点
 * @version 0.1
 * @date 2022-12-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// 添加依赖项
#include <chrono>
#include <functional>
#include <memory>
#include <string>

// ROS2常用依赖
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

// 创建class继承Node
class MinimalPublisher : public rclcpp::Node
{
    public:
        // 创建节点minimal_publisher  并初始化参数count_
        MinimalPublisher() : Node("minimal_publisher"), count_(0)
        {
            // this指代节点，确定话题，发布频率
            publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
            // 调用回调定时器
            timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
        }

    private:
        // 定时器回调函数（功能函数）
        void timer_callback()
        {
            auto message = std_msgs::msg::String();
            message.data = "Hello, world! " + std::to_string(count_++);
            // ROS2常见log使用方法
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
            publisher_->publish(message);
        }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        size_t count_;
};

// 主函数
int main(int argc, char * argv[])
{
    // 初始化
    rclcpp::init(argc, argv);
    // spin
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    // shutdown
    rclcpp::shutdown();
    return 0;
}
