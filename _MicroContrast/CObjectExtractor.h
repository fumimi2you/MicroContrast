#pragma once

#include "CMicroContrast.h"


typedef std::vector<std::vector<cv::Point> > Contours;

class CObjectExtractor
{
public:
	CObjectExtractor();
	~CObjectExtractor();

	static Contours Execute( const cv::Mat& imgSrc);
};

