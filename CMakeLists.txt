cmake_minimum_required(VERSION 3.1)
project(media_pipe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenCV_DIR /usr/local/lib/cmake/opencv4)
find_package(OpenCV REQUIRED)

add_executable(OpenCVWebcamApp main.cpp)


# Link OpenCV libraries
target_link_libraries(OpenCVWebcamApp PRIVATE ${OpenCV_LIBS})

# Include OpenCV headers
target_include_directories(OpenCVWebcamApp PRIVATE ${OpenCV_INCLUDE_DIRS})

message(STATUS "OpenCV version: ${OpenCV_VERSION}")