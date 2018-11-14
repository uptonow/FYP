#pragma once
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class Sampling
{
public:
	Sampling(VideoCapture capture, int frame_width, int frame_height);
	bool Sampling_process(VideoCapture capture, String address);

private:
	int count;
	char start;
	char finish;
	Mat pic;
};

