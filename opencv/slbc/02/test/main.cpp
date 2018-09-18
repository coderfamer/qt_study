#include <QCoreApplication>
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

//    cv::Mat image1;

//    cv::Mat image2(6, 6, CV_8UC1);

//    cv::Mat image3(cv::Size(7, 7), CV_8UC3);

      cv::Mat image4(8, 8, CV_32FC2, cv::Scalar(1, 3));

//    cv::Mat image5(cv::Size(9, 9), CV_8UC3, cv::Scalar(1, 2, 3));

//    cv::Mat image6(image2);

    std::cout << 1 << std::endl;
//    std::cout << image1 << std::endl;
//    std::cout << image2 << std::endl;
//    std::cout << image3 << std::endl;
//    std::cout << image4 << std::endl;
//    std::cout << image5 << std::endl;
//    std::cout << image6 << std::endl;
    std::cout << image4.rowRange(1, 3) << std::endl;
    std::cout << 7 << std::endl;

    system("pause");
    return a.exec();
}
