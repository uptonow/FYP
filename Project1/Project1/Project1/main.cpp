#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
using namespace cv;

int main()
{
	VideoCapture capture(0);
	capture.set(CAP_PROP_FRAME_WIDTH, 1280);
	capture.set(CAP_PROP_FRAME_HEIGHT, 720);
	int count = 1;
	Mat pic;
	char start = 'n';
	char finish = 'n';


	while (1)
	{
		if (capture.isOpened())
		{
			std::cout << "Start? y/n" << std::endl;
			std::cin >> start;
			if (start == 'y' || start == 'Y')
			{
				for (int i = 0; i < 300; i++)
				{
					if (capture.isOpened())
					{
						capture >> pic;
						std::string img = "D:\\FYP\\PHOTO\\" + std::to_string((i + 1)) + ".bmp";
						imwrite(img, pic);
					}
					else
						continue;
				}
			}
			std::cout << "Finish? Y/N" << std::endl;
			std::cin >> finish;
			if (finish == 'y' || finish == 'Y')break;
		}
		else
		{
			std::cout << "Warning No Camera" << std::endl;
			break;
		}
		
	}

	return 0;
}
