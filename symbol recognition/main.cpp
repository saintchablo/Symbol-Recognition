// Include files for required libraries
#include <stdio.h>
#include "opencv_aee.hpp"
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/imgproc/types_c.h"
#include "opencv2/imgproc/detail/distortion_model.hpp"
#include "opencv2/imgproc/hal/hal.hpp"
#include "opencv2/imgproc/hal/interface.h"
using namespace cv;
using namespace std;
// Function to threshold the image for a specific color range
Mat thresholdForColor(const Mat& hsvImage, const Scalar& lowerBound, const Scalar&
upperBound) {
 Mat mask;
 inRange(hsvImage, lowerBound, upperBound, mask);
 return mask;
}
// Function to check if a color is present in the image
bool isColorPresent(const Mat& mask) {
 int nonZeroCount = countNonZero(mask);
 // Threshold might need adjustment based on the image size and expected object size
 return nonZeroCount > 100;
}
int main() {
 // Load the image
 Mat image = imread("Circle.png");
 Mat image1 = imread("Circle.png");
 if (image.empty()) {
 cerr << "Error loading the image" << endl;
 return -1;
 }
 // Convert to HSV color space
 Mat hsvImage;
 Mat hsvImage1;
 cvtColor(image, hsvImage, COLOR_BGR2HSV);
 cvtColor(image1, hsvImage1, COLOR_BGR2HSV);
 // Define HSV ranges for different colors (These values are placeholders)
 Scalar lowerPink(99,90,117), upperPink(179,225,200);
 Scalar lowerBlue(99, 115, 86), upperBlue(107, 255, 255);
 Scalar lowerGreen(58, 103, 49), upperGreen(92, 255, 255);
 Scalar lowerRed(0, 197, 131), upperRed(179, 255, 255);
 // Threshold the image for each color
 Mat pinkMask = thresholdForColor(hsvImage, lowerPink, upperPink);
 Mat pinkMask1 = thresholdForColor(hsvImage1, lowerPink, upperPink);
 // Check the presence of each colour
 if (isColorPresent(pinkMask)) {
 float match = compareImages(pinkMask1, pinkMask);
 //cout << "This is a Circle" << endl;
 cout << match << endl;
 imshow("Compared photo", pinkMask1);
 imshow ("Circle symbol", pinkMask);
 }

 rotate(frame, frame, ROTATE_180); //rotate image 180 degree
 //Send an 16 bit integer
 arduino.i2cWriteArduinoInt(y);
 waitKey(0);
 destroyAllWindows();
 return 0;
}
