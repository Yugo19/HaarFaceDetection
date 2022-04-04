#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>


void main()
{

	cv::VideoCapture cap(0);
	cv::Mat frame;

	cv::CascadeClassifier faceCascade;
	faceCascade.load("C:\\Users\\Wakfu\\Documents\\OpenCV\\build\\install\\etc\\haarcascades\\haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) {
		std::cout << "XML file not loaded";
	}
	

	while (true)
	{
		cap >> frame;
		std::vector<cv::Rect> faces;
		faceCascade.detectMultiScale(frame, faces, 1.1, 10);
		for (int i = 0; i < faces.size(); i++)
		{
			cv::rectangle(frame, faces[i].tl(), faces[i].br(), cv::Scalar(0, 255, 0), 3);
			cv::putText(frame, "Face", { faces[i].x, faces[i].y - 5 }, cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 0, 255), 1);
		}
		cv::imshow("video", frame);
		cv::waitKey(20);
	}
}