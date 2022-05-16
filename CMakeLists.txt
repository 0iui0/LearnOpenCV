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

add_executable(Test src/Test.cpp)

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

add_executable(ImageFiltering src/ImageFiltering.cpp)
target_link_libraries(ImageFiltering ${OpenCV_LIBRARIES})

add_executable(EdgeDetection src/EdgeDetection.cpp)
target_link_libraries(EdgeDetection ${OpenCV_LIBRARIES})

add_executable(ContourDetection src/ContourDetection.cpp)
target_link_libraries(ContourDetection ${OpenCV_LIBRARIES})

add_executable(BackgroundEstimation src/BackgroundEstimation.cpp)
target_link_libraries(BackgroundEstimation ${OpenCV_LIBRARIES})

add_executable(OpenCVDNN src/OpenCVDNN.cpp)
target_link_libraries(OpenCVDNN ${OpenCV_LIBRARIES})