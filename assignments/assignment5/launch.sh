#!/bin/bash

source ~/Desktop/ProgrammingForMechatronicSystems/assignments/assignment5/catkin_ws/devel/setup.bash
roscd
cd ..
xterm -hold -e rosrun stage_ros stageros $(rospack find a5_help)/worlds/uoa_robotics_lab.world &
xterm -hold -e rosrun a5_help TBK2 &
xterm -hold -e rosrun local_map local_map /local_map/scan:=/base_scan_1 _map_width:=200 _map_height:=200 _map_resolution:=0.1 &
xterm -hold -e rosrun a5_help map_to_image_node map:=/local_map/local_map /pose:=/odom &
xterm -hold -e rosrun rviz rviz -d $(rospack find a5_help)/rviz/pfms.rviz &
xterm -hold -e rqt_image_view
