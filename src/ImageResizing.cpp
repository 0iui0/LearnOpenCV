//
// Created by ionic on 2022/5/14.
//
// let's start with including libraries
#include<opencv2/opencv.hpp>
#include<iostream>

// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;

int main() {
    // Read the image using imread function
    Mat image = imread("../data/car.jpg");
    imshow("Original Image", image);
    // lets downscale the image using new  width and height
    int down_width = 300;
    int down_height = 200;
    Mat resized_down;
    //resize down
    resize(image, resized_down, Size(down_width, down_height), INTER_LINEAR);
    // let's upscale the image using new  width and height
    int up_width = 600;
    int up_height = 400;
    Mat resized_up;
    //resize up
    resize(image, resized_up, Size(up_width, up_height), INTER_LINEAR);
    // Display Images and press any key to continue
    imshow("Resized Down by defining height and width", resized_down);
    waitKey();
    imshow("Resized Up image by defining height and width", resized_up);
    waitKey();
    destroyWindow("Resized Down by defining height and width");
    destroyWindow("Resized Up image by defining height and width");

    // Scaling Up the image 1.2 times by specifying both scaling factors
    double scale_up_x = 1.2;
    double scale_up_y = 1.2;
    // Scaling Down the image 0.6 times specifying a single scale factor.
    double scale_down = 0.6;
    Mat scaled_f_up, scaled_f_down;
    //resize
    resize(image, scaled_f_down, Size(), scale_down, scale_down, INTER_LINEAR);
    resize(image, scaled_f_up, Size(), scale_up_x, scale_up_y, INTER_LINEAR);
    // Display images and Press any key to continue check next image
    imshow("Resized Down by defining scaling factor", scaled_f_down);
    waitKey();
    imshow("Resized Up by defining scaling factor", scaled_f_up);
    waitKey();
    destroyWindow("Resized Down by defining scaling factor");
    destroyWindow("Resized Up by defining scaling factor");

    // Scaling Down the image 0.6 using different Interpolation Method
    Mat res_inter_linear, res_inter_nearest, res_inter_area;
    resize(image, res_inter_linear, Size(), scale_down, scale_down, INTER_LINEAR);
    resize(image, res_inter_nearest, Size(), scale_down, scale_down, INTER_NEAREST);
    resize(image, res_inter_area, Size(), scale_down, scale_down, INTER_AREA);
    Mat a, b, c;
    vconcat(res_inter_linear, res_inter_nearest, a);
    vconcat(res_inter_area, res_inter_area, b);
    vconcat(a, b, c);
    // Display the image Press any key to continue
    imshow("Inter Linear :: Inter Nearest :: Inter Area :: Inter Area", c);
    waitKey();

    destroyAllWindows();
    return 0;
}