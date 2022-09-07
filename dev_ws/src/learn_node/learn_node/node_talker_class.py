#!/usr/bin/env python3
# _*_ coding: utf-8 _*_

# 创建一个talker的节点 发布消息"talker say: Hello World"
# owner:lio

import rclpy                                                    # ROS2 Python接口库
from rclpy.node import Node                                     # ROS2 节点类
import time

class HelloWorldNode(Node):
    def __init__(self, name):
        super().__init__(name)                                  # ROS2节点父类初始化
        while rclpy.ok():                                       # ROS2系统是否正常运行
            self.get_logger().info("talker say: Hello World")   # ROS2日志输出
            time.sleep(0.5)                                     # 休眠控制循环时间

def main(args=None):                                            # ROS2节点主入口main函数
    rclpy.init(args=args)                                       # ROS2 Python接口初始化
    node = HelloWorldNode("node_talker_class")                  # 创建ROS2节点对象并进行初始化
    node.destroy_node()                                         # 销毁节点对象
    rclpy.shutdown()                                            # 关闭ROS2 Python接口