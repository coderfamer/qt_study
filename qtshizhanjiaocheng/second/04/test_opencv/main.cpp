#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[])
{

    Mat img;
    img = imread("E:\\libs\\test.jpg");
    namedWindow("显示");
    imshow("显示", img);
    waitKey(0);
    return 0;
}
