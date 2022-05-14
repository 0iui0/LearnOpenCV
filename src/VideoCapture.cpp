//
// Created by iouoi on 2022/5/14.
//
// Include Libraries
#include<opencv2/opencv.hpp>
#include<iostream>

// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;

int main() {
    // initialize a video capture object
    VideoCapture vid_capture(0);
    int fps, frame_count, frame_width, frame_height;
    if (vid_capture.isOpened()) {
        // Obtain fps and frame count by get() method and print
        // You can replace 5 with CAP_PROP_FPS as well, they are enumerations
        fps = vid_capture.get(CAP_PROP_FPS);
        cout << "Frames per second :" << fps << endl;
        // Obtain frame_count using opencv built in frame count reading method
        // You can replace 7 with CAP_PROP_FRAME_COUNT as well, they are enumerations
        frame_count = vid_capture.get(CAP_PROP_FRAME_COUNT);
        cout << "Frame count :" << frame_count << endl;
        frame_width = vid_capture.get(CAP_PROP_FRAME_WIDTH);
        cout << "Frame width :" << frame_count << endl;
        frame_height = vid_capture.get(CAP_PROP_FRAME_HEIGHT);
        cout << "Frame height :" << frame_count << endl;
    } else {
        // Print error message if the stream is invalid
        cout << "Error opening video stream or file" << endl;
    }
    Size frame_size(frame_width, frame_height);
    //Initialize video writer object
    VideoWriter output("/tmp/output.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, frame_size);
    // Read the frames to the last frame
    while (vid_capture.isOpened()) {
        // Initialise frame matrix
        Mat frame;
        // Initialize a boolean to check if frames are there or not
        bool isSuccess = vid_capture.read(frame);
        // If frames are present, show it
        if (isSuccess) {
            //display frames
            imshow("Frame", frame);
            //write frame
            output.write(frame);
        }
        // If frames are not there, close it
        if (!isSuccess) {
            cout << "Video camera is disconnected" << endl;
            break;
        }
        //wait 20 ms between successive frames and break the loop if key q is pressed
        int key = waitKey(20);
        if (key == 'q') {
            cout << "q key is pressed by the user. Stopping the video" << endl;
            break;
        }
    }
    // Release the video capture object
    vid_capture.release();
    destroyAllWindows();
    output.release();
    return 0;
}