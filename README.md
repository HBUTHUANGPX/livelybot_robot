你该如何得到这个工程：<br>
在香橙派中任意打开一个终端，cd /home/orangepi,随后<br>

```git clone --recurse-submodules https://github.com/HBUTHUANGPX/livelybot_robot.git```

等待结束后，cd livelybot_robot ，catkin build<br>

不出意外的，catkin build编译需要进行两次，这是一个小bug，目前不会去修复，报错仅仅只会在第一次编译时出现。
编译完成后即可。<br>

关于如何快速使用本工程：
1.本项目依赖于ROS构建。主要使用ROS的rosparam的api对yaml文件进行读取，以方便抽象化构建代码。
2.在livelybot_robot/src/livelybot_description/rosparam中存在一些参数文件，参数文件的命名的规则是<br>
(1)```<arg name = "dof_type" default = "10"/>```<br>
(2)```<arg name = "mcu_type" default = "STM32H730"/>```<br>
(3)```<arg name = "model_type" default = "P"/>```<br>
(4)```<arg name = "design" default = "Hector"/>```  <br>
这里我以roslaunch(xml)的语法来表达文件名字的组合形式<br>```$(arg dof_type)dof_$(arg mcu_type)_model_$(arg model_type)_$(arg design)_params.yaml```<br>
3.依赖：<br>
(1)Ubuntu 20.04 LTS<br>
(2)ros-noetic<br>
安装方式参考鱼香ros的一键安装,建议安装桌面版:<br>```wget http://fishros.com/install -O fishros && . fishros```<br>
(3)LCM<br>
git clone --branch v1.4.0 https://github.com/lcm-proj/lcm.git
(4)ros-moveit<br>
安装方式: ```sudo apt-get install ros-noetic-moveit* -y```<br>