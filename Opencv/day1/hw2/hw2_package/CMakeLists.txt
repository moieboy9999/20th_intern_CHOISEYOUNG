cmake_minimum_required(VERSION 3.8)
project(hw2_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(image_transport REQUIRED)

# add_executable(hw2 src/hw2.cpp)
# ament_target_dependencies(hw2 rclcpp sensor_msgs cv_bridge OpenCV)

add_executable(server src/server.cpp)
ament_target_dependencies(server rclcpp sensor_msgs cv_bridge OpenCV image_transport)

# add_executable(client src/client.cpp)
# ament_target_dependencies(client rclcpp sensor_msgs cv_bridge OpenCV)

# add_executable(server include/hw2_package/server.hpp)
# ament_target_dependencies(server rclcpp sensor_msgs cv_bridge OpenCV image_transport)

install(TARGETS
  # hw2
  server

  # client
  DESTINATION lib/${PROJECT_NAME}
)

install(FILES
  src/test.png
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
