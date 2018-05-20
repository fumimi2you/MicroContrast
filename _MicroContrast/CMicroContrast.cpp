#include "stdafx.h"
#include "CMicroContrast.h"


CMicroContrast::CMicroContrast()
{
}


CMicroContrast::~CMicroContrast()
{
}


cv::Mat CMicroContrast::CoreExecute(const cv::Mat& imgSrc )
{
	assert(imgSrc.type() == CV_8UC1);


	const auto sizSrc = imgSrc.size();

	//	適応的にヒストグラムの平滑化
	cv::Mat imgEH = imgSrc.clone();	
//	cv::equalizeHist(imgSrc, imgEH);
	auto clahe = cv::createCLAHE(8, cv::Size(8, 8));
	clahe->apply(imgSrc, imgEH);


	//	まずは浮動少数化
	cv::Mat ifEH;
	imgSrc.convertTo(ifEH, CV_32FC1, 1. / 255.);


	//	ぼかした画像で割る
	cv::Mat ifBlur;
	cv::resize(ifEH, ifBlur, cv::Size(), 0.25, 0.25, cv::INTER_AREA);
	cv::GaussianBlur(ifBlur, ifBlur, cv::Size(7, 7), 0);
	cv::resize(ifBlur, ifBlur, sizSrc, 0, 0, cv::INTER_CUBIC);
	cv::Mat ifDived = (ifEH / ifBlur);


	//	レンジを整える
	cv::Mat ifDived2;
	cv::resize(ifDived, ifDived2, cv::Size(), 0.25, 0.25, cv::INTER_AREA);
	double vMin, vMax;
	cv::minMaxIdx(ifDived2, &vMin, &vMax);

	cv::Mat ifNorl = ifDived.clone();
	float* pfS = (float*)ifDived.ptr();
	float* pfD = (float*)ifNorl.ptr();
	for (int i = 0; i < ifDived.rows*ifDived.cols; i++)
	{
		pfD[i] = float( (pfS[i] - vMin) / (vMax - vMin) );
	}


	//	8bitに戻す
	cv::Mat imgNrol;
	ifNorl.convertTo(imgNrol, CV_8UC1, 255);


	//	ヒストグラムを整える
	cv::Mat imgRet = imgNrol.clone();
//	cv::equalizeHist(imgNrol, imgRet);
//	auto clahe = cv::createCLAHE(2, cv::Size(8, 8));
//	clahe->apply(imgNrol, imgRet);


	if (0)
	{
		cv::imshow("imgSrc", imgSrc);
		cv::imshow("ifEH", ifEH);
		cv::imshow("imgNrol", imgNrol);
		cv::imshow("imgRet", imgRet);
		cv::waitKey(0);
	}


	return imgRet;
}


cv::Mat CMicroContrast::Execute(const cv::Mat& imgSrc)
{
	std::vector<cv::Mat> planes;

	// 3つのチャネルB, G, Rに分離 (OpenCVではデフォルトでB, G, Rの順)
	cv::split(imgSrc, planes);
	for (auto& itr : planes)
	{
		itr = CoreExecute(itr);
	}

	cv::Mat imgRet;
	cv::merge(planes, imgRet);

	return imgRet;
}
