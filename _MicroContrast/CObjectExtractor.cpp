#include "stdafx.h"
#include "CObjectExtractor.h"


CObjectExtractor::CObjectExtractor()
{
}


CObjectExtractor::~CObjectExtractor()
{
}


Contours CObjectExtractor::Execute(const cv::Mat& imgSrc)
{
	std::vector<cv::Mat> planes;
	cv::split(imgSrc, planes);

	cv::Mat imgCannyAll = cv::Mat::zeros( imgSrc.size(), CV_8UC1);
	for (auto& itr : planes)
	{
		cv::Mat imgMid;
		cv::medianBlur(itr, imgMid, 3);

		auto imgMC = CMicroContrast::CoreExecute(imgMid);

		cv::Mat imgCanny;
		cv::Canny(imgMC, imgCanny, 32, 128);
		cv::dilate(imgCanny, imgCanny, cv::Mat(), cv::Point(-1, -1), 4);
		cv::erode(imgCanny, imgCanny, cv::Mat(), cv::Point(-1, -1), 3);

		imgCannyAll |= imgCanny;
	}

	Contours contours;
	cv::findContours(imgCannyAll, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	cv::Mat imgContour = imgSrc.clone();
	for (auto contour = contours.begin(); contour != contours.end(); contour++) {
		cv::polylines(imgContour, *contour, true, cv::Scalar(255, 0, 255), 1);
	}

	cv::imshow("imgCannyAll", imgCannyAll);
	cv::imshow("imgContour", imgContour);
	cv::waitKey(0);


	return contours;
}
