#include "Sampling.h"


Sampling::Sampling(VideoCapture capture, int frame_width, int frame_height)
{
	capture.set(CAP_PROP_FRAME_WIDTH, frame_width);
	capture.set(CAP_PROP_FRAME_HEIGHT, frame_height);
	char start = 'n';
	char finish = 'n';
	Mat pic;
}


bool Sampling::Sampling_process(VideoCapture capture, String address)
{
	while (1)
	{
		if (capture.isOpened())
		{
			std::cout << "Open camera successfully!" << std::endl;
			std::cout << "Start? y/n" << std::endl;
			std::cin >> start;
			if (start == 'y' || start == 'Y')
			{
				std::cout << "Working!" << std::endl;

				for (int i = 0; i < 300; i++)
				{
					if (capture.isOpened())
					{
						capture >> pic;
						std::string img = address + std::to_string((i + 1)) + ".bmp";
						imwrite(img, pic);
					}
					else
						continue;
				}
			}
			std::cout << "Finish? Y/N" << std::endl;
			std::cin >> finish;
			if (finish == 'y' || finish == 'Y')return true;
		}
		else
		{
			std::cout << "Warning No Camera" << std::endl;
			return false;
		}

	}
}
