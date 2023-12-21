cmake_minimum_required(VERSION 3.0.2)
project(livelybot_moveit)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  livelybot_serial
  livelybot_msg
  moveit_ros_planning
  moveit_ros_planning_interface
  moveit_core
)

catkin_package(
    CATKIN_DEPENDS  moveit_core
    livelybot_msg 
    INCLUDE_DIRS include
)
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(main src/test_get_jocbia.cpp  ${SRC_LIST} )
target_link_libraries(main ${catkin_LIBRARIES})


install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  PATTERN "setup_assistant.launch" EXCLUDE)
install(DIRECTORY config DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
