cmake_minimum_required(VERSION 3.23)
project(LearnOpenCV)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED QUIET)
include_directories(
        include
        ${OpenCV_INCLUDE_DIRS}
)

link_directories(
        include
        ${OpenCV_LIBRARIES}
)

add_executable(VideoCapture
        include/header.h
        src/VideoCapture.cpp)
target_link_libraries(VideoCapture ${OpenCV_LIBRARIES})

add_executable(ImageResizing src/ImageResizing.cpp)
target_link_libraries(ImageResizing ${OpenCV_LIBRARIES})

add_executable(ImageRotandTrans src/ImageRotandTrans.cpp)
target_link_libraries(ImageRotandTrans ${OpenCV_LIBRARIES})

add_executable(Annotating src/Annotating.cpp)
target_link_libraries(Annotating ${OpenCV_LIBRARIES})