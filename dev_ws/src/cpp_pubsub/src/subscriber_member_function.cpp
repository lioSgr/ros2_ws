/**
 * @file subscriber_member_function.cpp
 * @author lio (lioSgr@126.com)
 * @brief 创建订阅者
 * @version 0.1
 * @date 2022-12-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// 添加依赖
#include <functional>
#include <memory>

// ROS2常用依赖项
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

// 创建class 继承Node
class MinimalSubscriber : public rclcpp::Node
{
    public:
        // 创建节点minimal_subscriber
        MinimalSubscriber() : Node("minimal_subscriber")
        {
          subscription_ = this->create_subscription<std_msgs::msg::String>(
            "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
        }

    private:
        // 创建话题回调函数
        void topic_callback(const std_msgs::msg::String & msg) const
        {
            // ROS2常见log使用方法
            RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
        }
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

// 主函数
int main(int argc, char * argv[])
{
    // 初始化
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();
    return 0;
}
