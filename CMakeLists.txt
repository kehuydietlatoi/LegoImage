cmake_minimum_required(VERSION 3.19)
project(LegoImage)

set(CMAKE_CXX_STANDARD 14)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable(LegoImage main.cpp)
target_link_libraries( LegoImage ${OpenCV_LIBS} )