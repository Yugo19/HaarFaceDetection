#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>




/*        //////////   /////////          */
void main()
{

	cv::Mat img(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::circle(img, cv::Point(256, 256), 150, cv::Scalar(0, 120, 255), cv::FILLED);
	cv::rectangle(img, cv::Point(130, 216), cv::Point(382, 286), cv::Scalar(255, 255, 255), cv::FILLED);
	cv::line(img, cv::Point(130, 296), cv::Point(382, 296), cv::Scalar(255, 255, 255), 2);

	cv::putText(img, "Yugo", cv::Point(130, 262), cv::FONT_HERSHEY_DUPLEX, 0.75, cv::Scalar(0, 69, 255), 2);
	cv::imshow("image", img);
	cv::waitKey(0);


}
