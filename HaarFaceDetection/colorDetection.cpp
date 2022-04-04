#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

cv::Mat imgHSV, imgResied, mask;

int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

void main()
{
	std::string path = "C:\\Users\\Wakfu\\Videos\\Captures\\ForzaHorizon5.png";

	cv::Mat img = cv::imread(path);

	cv::resize(img, imgResied, cv::Size(), 0.5, 0.5);

	cv::cvtColor(imgResied, imgHSV, cv::COLOR_BGR2HSV);

	cv::namedWindow("Trackbars", (640, 200));
	cv::createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	cv::createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	cv::createTrackbar("Sat Min", "Trackbars", &smin, 255);
	cv::createTrackbar("Sat Max", "Trackbars", &smax, 255);
	cv::createTrackbar("Val Min", "Trackbars", &vmin,255);
	cv::createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {
		cv::Scalar lower(hmin, smin, vmin);
		cv::Scalar upper(hmax, smax, vmax);
		cv::inRange(imgHSV, lower, upper, mask);

		cv::imshow("img", imgResied);
		cv::imshow("imgHSV", imgHSV);
		cv::imshow("mask", mask);

		cv::waitKey(1);

	}
}