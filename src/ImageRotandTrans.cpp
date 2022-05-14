//
// Created by ionic on 2022/5/15.
//
#include <iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

int main() {
    Mat image = imread("../data/car.jpg");
    imshow("car", image);
    waitKey(0);

    //// rotation matrix.
    double angle = 45;
    // get the center coordinates of the image to create the 2D rotation matrix
    Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
    // using getRotationMatrix2D() to get the rotation matrix
    Mat rotationMatix = getRotationMatrix2D(center, angle, 1.0);

    // we will save the resulting image in rotated_image matrix
    Mat rotated_image;
    // rotate the image using warpAffine
    warpAffine(image, rotated_image, rotationMatix, image.size());
    imshow("Rotated image", rotated_image);
    // wait indefinitely, press any key on keyboard to exit
    waitKey(0);
    // save the rotated image to disk
    // imwrite("rotated_im.jpg", rotated_image);

    //// translation matrix.
    // get the height and width of the image
    int height = image.cols;
    int width = image.rows;
    // get tx and ty values for translation
    float tx = float(width) / 4;
    float ty = float(height) / 4;
    // create the translation matrix using tx and ty
    float warp_values[] = { 1.0, 0.0, tx, 0.0, 1.0, ty };
    Mat translation_matrix = Mat(2, 3, CV_32F, warp_values);
    // save the resulting image in translated_image matrix
    Mat translated_image;
    // apply affine transformation to the original image using the translation matrix
    warpAffine(image, translated_image, translation_matrix, image.size());
    //display the original and the Translated images
    imshow("Translated image", translated_image);
    waitKey(0);
    // save the translated image to disk
    // imwrite("translated_image.jpg", translated_image);

    return 0;
}
