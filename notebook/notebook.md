# ros和ros2对比

1、结构

    ros有master

    ros2使用discover的机制

2、通信

    ros 使用tcp

    ros2使用DDS

3、支持系统

    ros支持linux

    ros2全平台支持

4、命令行

    ros命令行分散

    ros2命令行集成

# ros-humble LTS

## 使用测试案例测试ros2系统安装是否成功

### 案例一、

ros2 run demo_nodes_cpp listener

ros2 run demo_nodes_py talker

### 案例二、

ros2 run turtlesim turtlesim_node

使用方向按键可实现小乌龟前进 后退 左旋转 右旋转

# linux常用命令

## 系统命令

pwd

ls

ls -a

mkdir  forldName

cd forldName

touch fileName

rm fileName

cd ..

rm -r forldName

sudo apt install appName

## ROS2命令

ros2 run pkg node

ros2 node list

ros2 node info

ros2 topic list

ros2 topic echo

ros2 topic pub

ros2 topic type

ros2 service

ros2 bag record

ros2 bag play

# ROS2开发环境配置

## 软件git

sudo apt install git

## 软件vscode

官方下载deb包

sudo dpkg -i xxx.deb

### 常见插件

中文汉化包	不建议使用

python

c/c++

cmake

icons

ros

msg

urdf

intellicode

markdown

# ROS2黑话解释

工作空间

    项目空间

src

    代码空间

install

    安装空间

build

    编译空间

log

    日志空间

## 安装编译工具

sudo apt install python3-colcon-ros

## 配置环境变量

source install/setup.sh

## 创建功能包

### cpp pkg

ros2 pkg create --build-type ament_cmake pkgName

### py pkg

ros2 pkg create --build-type ament_py pkgName


# ROS2 node节点

机器人的工作细胞：可以理解为计算机线程，可以使用不同类型的计算机语言进行编写

py包要进行设置才能使用ros进行运行node

节点名字=pkgName.fileName:funName





noteDate：2022-09-07
