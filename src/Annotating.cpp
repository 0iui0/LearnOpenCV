//
// Created by ionic on 2022/5/15.
//
#include<opencv2/opencv.hpp>
#include<iostream>

// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;

int main() {
    // Read Image
    Mat img = imread("../data/dog.jpg");
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
    Point circle_center(415,190);
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
    putText(circle_image, "I am a Happy dog!", Point(50,350), FONT_HERSHEY_COMPLEX, 1.5, Scalar(250,225,100));
    imshow("Text on Image", circle_image);
    waitKey(0);
    return 0;
}