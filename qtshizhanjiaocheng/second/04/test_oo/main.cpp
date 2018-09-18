#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    Mat img;
    img = imread("E:/qt_study/qtshizhanjiaocheng/second/04/test_o/testp.jpg", 1);
    namedWindow("显示");

    Size dsize = Size(img.cols * 0.3, img.rows * 0.3);
    Mat dst(dsize, img.type());
    resize(img, dst, dst.size(), 0.5, 0.5);

    imshow("显示", dst);
    waitKey(0);
    return 0;
}
