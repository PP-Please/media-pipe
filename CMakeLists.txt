cmake_minimum_required(VERSION 3.1)
project(media_pipe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

add_executable(OpenCVWebcamApp main.cpp)

target_link_libraries(OpenCVWebcamApp PRIVATE ${OpenCV_LIBS})

message(STATUS "OpenCV version: ${OpenCV_VERSION}")