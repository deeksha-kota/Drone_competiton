cmake_minimum_required (VERSION 2.8)

project(tello-vision)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(tello-vision tello-vision.cpp)

target_link_libraries(tello-vision ${OpenCV_LIBS})
