#include "Sampling.h"

Mat original_img, boxfilter_img, meanblur_img, Gaussianblur_img, medianblur_img,bilateralfilter_img;
int bf_para = 3;
int	mb_para = 3;
int	gb_para = 3;
int meb_para = 3;
int bif_para = 3;

static void use_BoxFilter(int, void*)
{
	boxFilter(original_img, boxfilter_img, -1, Size(bf_para + 1, bf_para + 1));
	imshow("BoxFilter", boxfilter_img);
}

static void use_Blur(int, void*)
{
	blur(original_img, meanblur_img, Size(mb_para + 1, mb_para + 1));
	imshow("MeanBlur", meanblur_img);
}

static void use_GaussianBlur(int, void*)
{
	GaussianBlur(original_img, Gaussianblur_img, Size(gb_para * 2 + 1, gb_para * 2 + 1), 0, 0);
	imshow("GaussianBlur", Gaussianblur_img);
}

static void use_MedianBlur(int, void*)
{
	medianBlur(original_img, medianblur_img, meb_para*2+1);
	imshow("MedianBlur", medianblur_img);
}

static void use_BilateralFilter(int, void*)
{
	bilateralFilter(original_img, bilateralfilter_img, bif_para,bif_para*2,bif_para/2.0);
	imshow("BilateralFilter", bilateralfilter_img);
}

int main()
{
	/**** Sampling process

	VideoCapture capture(0);
	Sampling sample(capture,1280,720);

	if (sample.Sampling_process(capture,"D://FYP//PHOTO//"))
		std::cout << "OJBK";
	else
		std::cout << "ARE YOU OK?";
	*/

	original_img = imread("D://FYP//2//242.bmp", IMREAD_GRAYSCALE);
	if (!original_img.data)
	{
		std::cout << "Fail to read image!";
		return false;
	}

	namedWindow("BoxBlur");
	createTrackbar("ksize:", "BoxBlur", &bf_para, 40, use_BoxFilter);
	use_BoxFilter(bf_para, 0);

	namedWindow("MeanBlur");
	createTrackbar("ksize:", "MeanBlur", &mb_para, 40, use_Blur);
	use_Blur(mb_para, 0);

	namedWindow("GaussianBlur");
	createTrackbar("ksize:", "GaussianBlur", &gb_para, 40, use_GaussianBlur);
	use_GaussianBlur(gb_para, 0);

	namedWindow("MedianBlur");
	createTrackbar("ksize:", "MedianBlur", &meb_para, 40, use_MedianBlur);
	use_MedianBlur(meb_para, 0);

	namedWindow("BilateralFilter");
	createTrackbar("ksize:", "BilateralFilter", &bif_para, 40, use_BilateralFilter);
	use_BilateralFilter(bif_para, 0);

	while(char(waitKey(1))!='q'){ }

	getchar();
	return 0;
}
