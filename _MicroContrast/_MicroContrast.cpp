// _MicroContrast.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include <string>

#include "CObjectExtractor.h"



int main()
{
	std::string pathImg = "737179.jpg";
	cv::Mat imgOrg = cv::imread(pathImg);

	cv::Mat imgRis;
	cv::resize(imgOrg, imgRis, cv::Size(), 0.5, 0.5, cv::INTER_CUBIC);


	auto contours = CObjectExtractor::Execute(imgRis);
/*
	auto imgRet = CMicroContrast::Execute(imgRis);


	cv::Mat imgGray;
	cv::cvtColor(imgRet, imgGray, CV_BGR2GRAY);
	cv::Mat imgCanny;
	cv::Canny(imgGray, imgCanny, 32, 64 );
	cv::dilate(imgCanny, imgCanny, cv::Mat(), cv::Point(-1, -1), 3);
	cv::erode(imgCanny, imgCanny, cv::Mat(), cv::Point(-1, -1), 3);


	cv::imshow("imgRis", imgRis);
	cv::imshow("imgRet", imgRet);
	cv::imshow("imgCanny", imgCanny);
	cv::waitKey(0);
*/

    return 0;
}

