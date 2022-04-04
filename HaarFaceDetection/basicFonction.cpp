#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>




/*        //////////   /////////          */
void main()
{

	std::string path = "C:\\Users\\Wakfu\\Videos\\Captures\\CallOfDutty.png";
	cv::Mat img = cv::imread(path);
	cv::Mat imgRezied;
	cv::resize(img, imgRezied, cv::Size(), 0.5,0.5);
	cv::Mat imgGray, imgBlur, imgCanny, imgDilate, imgErode, imgCrop;

	cv::cvtColor(imgRezied, imgGray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(imgRezied, imgBlur, cv::Size(7,7),5,0);
	cv::Canny(imgBlur, imgCanny, 25, 75);

	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
	cv::dilate(imgCanny, imgDilate, kernel);
	cv::erode(imgDilate, imgErode, kernel);

	cv::imshow("image", imgRezied);
	//cv::imshow("imgGray", imgGray);
	//cv::imshow("imgBlur", imgBlur);
	//cv::imshow("Canny", imgCanny);
	//cv::imshow("Dilation", imgDilate);
	//cv::imshow("Erode", imgErode);

	cv::waitKey(0);


}
