//
// Created by ionic on 2022/5/15.
//
#include<opencv2/opencv.hpp>
#include<iostream>

// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;

// Points to store the bounding box coordinates
Point top_left_corner, bottom_right_corner;
// image image
Mat img;

// function which will be called on mouse input
void drawRectangle(int action, int x, int y, int flags, void *userdata) {
    // Mark the top left corner when left mouse button is pressed
    if (action == EVENT_LBUTTONDOWN) {
        top_left_corner = Point(x, y);
    }
        // When left mouse button is released, mark bottom right corner
    else if (action == EVENT_LBUTTONUP) {
        bottom_right_corner = Point(x, y);
        // Draw rectangle
        rectangle(img, top_left_corner, bottom_right_corner, Scalar(0, 255, 0), 2, 8);
        // Display image
        imshow("Window", img);
    }
}

int main() {
    // Read Image
    img = imread("../data/dog.jpg");
    // Display the Image
    imshow("Original Image", img);
    waitKey();
    // Print Error message if image is null
    if (img.empty()) {
        cout << "Could not read image" << endl;
    }

    // Make a copy of image
    Mat circle_image = img.clone();
    // define the center of circle
    Point circle_center(415, 190);
    // define the radius of circle
    int radius = 100;
    // Draw a circle using the circle() Function
    circle(circle_image, circle_center, radius, Scalar(0, 0, 255), 3, 8, 0);
    // Display the result
    imshow("Circle on Image", circle_image);
    waitKey(0);

    // make a copy of the original image
    Mat imageText = img.clone();
    // Write text using putText() function
    putText(imageText, "I am a Happy dog!", Point(50, 350), FONT_HERSHEY_COMPLEX, 1.5, Scalar(250, 225, 100));
    imshow("Text on Image", imageText);
    waitKey(0);



    // Make a temporary image, which will be used to clear the image
    Mat temp = img.clone();
    // Create a named window
    namedWindow("Window");
    // highgui function called when mouse events occur
    setMouseCallback("Window", drawRectangle);
    int k = 0;
    // loop until q character is pressed
    while (k != 113) {
        imshow("Window", img);
        k = waitKey(0);
        // If c is pressed, clear the window, using the dummy image
        if (k == 99) {
            temp.copyTo(img);
        }
    }
    destroyAllWindows();
    return 0;
}