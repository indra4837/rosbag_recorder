cmake_minimum_required(VERSION 3.0.2)
project(rosbag_recorder)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  rosbag
  roscpp
  std_msgs
)

# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

catkin_package(
  CATKIN_DEPENDS message_runtime rosbag roscpp std_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(
  ${PROJECT_NAME}_node 
  src/RosbagRecorder.cpp
  src/rosbag_recorder_node.cpp
)

add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})

install(
  PROGRAMS 
  scripts/rosbag_uploader.sh 
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )