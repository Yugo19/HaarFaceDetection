#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main()
{
 
    /*         //////////IMAGE///////////
    
    std::string path = "C:\\Users\\Wakfu\\OneDrive\\Images\\index.jpg";

    cv::Mat img = cv::imread(path);

    cv::imshow("img", img);
    cv::waitKey(0);
    */


    /*         //////////WEBCAM///////////
    cv::VideoCapture cap(0);

    if (!cap.isOpened())
    {
        return -1;
    }

    for (;;)
    {
        cv::Mat frame;
        cap >> frame;
        imshow("webcam", frame);

        if (cv::waitKey(30) >= 0)
            break;
    }
    */

    std::string path = "C:\\Users\\Wakfu\\Videos\\Captures\\COD.mp4";
    cv::VideoCapture cap(path);
    cv::Mat img;

    while (true)
    {
        cap >> img;

        cv::imshow("video", img);
        cv::waitKey(20);
       
    }

    return 0;
}

