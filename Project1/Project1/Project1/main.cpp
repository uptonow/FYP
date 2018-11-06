#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
using namespace cv;

int main()
{
	VideoCapture capture(1);
	capture.set(CAP_PROP_FRAME_WIDTH, 1280);
	capture.set(CAP_PROP_FRAME_HEIGHT, 720);

	for (int i = 0; i < 200; i++)
	{
		if (capture.isOpened())
		{
			Mat pic;
			capture >> pic;
			std::string img = "D:\\FYP\\PHOTO\\" + std::to_string((i + 1)) + ".bmp";
			imwrite(img, pic);
			//waitKey(5);
		}
		else
			continue;
	}


	while (1)
	{
		if (capture.isOpened())
		{
			Mat frame;
			capture >> frame;
			imshow("Read Canny Video", frame);
			if (waitKey(10) >= 0)break;
		}
		else
		{
			std::cout << "Warning No Camera" << std::endl;
			break;
		}
		
	}
	getchar();

	return 0;
}
