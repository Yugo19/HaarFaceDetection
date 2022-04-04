#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

cv::Mat imgResied, imgBlur, imgGray, ImgCanny, imgDilate;

void getCountours(cv::Mat imgDil, cv::Mat imgR)
{
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	cv::findContours(imgDilate, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	
	std::vector<std::vector<cv::Point>> conPoly(contours.size());
	std::vector<cv::Rect> boundRect(contours.size());
	std::string objectType;

	for (int i = 0; i < contours.size(); i++)
	{

		int area = cv::contourArea(contours[i]);
		std::cout << area << std::endl;
		if (area > 1000)
		{
			float peri = cv::arcLength(contours[i], true);
			cv::approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			
			boundRect[i] = cv::boundingRect(conPoly[i]);

			int objCorner = (int)conPoly[i].size();

			if (objCorner == 3) { objectType = "Triange";}
			if (objCorner == 4) { objectType = "Rect"; }
			if (objCorner > 3) { objectType = "circle"; }

			cv::drawContours(imgR, conPoly, i, cv::Scalar(255, 0, 255), 1);
			cv::rectangle(imgR, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(0, 255, 0), 5);
			cv::putText(imgR, objectType, { boundRect[i].x, boundRect[i].y - 5 }, cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 69, 255),1);

		}
	}
}

void main()
{
	std::string path = "C:\\Users\\Wakfu\\OneDrive\\Images\\shapes.jpg";

	cv::Mat img = cv::imread(path);

	cv::resize(img, imgResied, cv::Size(), 0.5, 0.5);
	cv::cvtColor(imgResied, imgGray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(imgGray, imgBlur, cv::Size(3, 3), 3, 0.0);
	cv::Canny(imgBlur, ImgCanny, 15,55);
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate(ImgCanny, imgDilate, kernel);

	getCountours(imgDilate, imgResied);

	cv::imshow("img", imgResied);
	cv::imshow("Gray", imgGray);
	cv::imshow("Blur", imgBlur);
	cv::imshow("canny", ImgCanny);
	cv::imshow("Dilate", imgDilate);
	cv::waitKey(0);

}