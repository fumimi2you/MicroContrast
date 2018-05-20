#pragma once


#include <opencv_libs.hpp>

#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>



class CMicroContrast
{
public:
	CMicroContrast();
	~CMicroContrast();


	static cv::Mat CoreExecute(const cv::Mat& imgSrc);
	static cv::Mat Execute(const cv::Mat& imgSrc);

};

