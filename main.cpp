#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
int main() {
    std::cout << "Hello, World!" << std::endl;
    namedWindow("Window", cv::WINDOW_AUTOSIZE); // Create a window
    float scaleBrick = 1;//default
    Mat legoBrick = imread("../1x1.png",IMREAD_COLOR);
    Mat frame = imread("../yoshi.png",IMREAD_COLOR);
    resize(legoBrick,legoBrick,Size(),scaleBrick,scaleBrick);
    auto BrickSize = legoBrick.cols;
    auto width = frame.cols;
    auto height = frame.rows;
    Mat image(width, height, CV_8UC3, cv::Scalar(0, 0, 0));
    Mat partialImg2(legoBrick.rowRange(0,BrickSize-1).colRange(0, BrickSize-1));
    Scalar averageBrick = cv::mean(partialImg2);
    for (int i =0; i < height/BrickSize ; i++) {
        for (int j = 0; j < width/BrickSize; ++j) {
            Mat partialImg(frame.rowRange(i*BrickSize, (i+1)*BrickSize).colRange(j*BrickSize, (j+1)*BrickSize));
            Scalar average = cv::mean(partialImg);
            Mat m = legoBrick + average - averageBrick;
            (m).copyTo(frame.rowRange(i*BrickSize, (i+1)*BrickSize).colRange(j*BrickSize, (j+1)*BrickSize));
        }
    }

    imshow("Window",frame);
    waitKey(0);
    return 0;
}
