#include "Sampling.h"


int main()
{
	VideoCapture capture(0);
	Sampling sample(capture,1280,720);

	if (sample.Sampling_process(capture,"D://FYP//PHOTO//"))
		std::cout << "OJBK";
	else
		std::cout << "ARE YOU OK?";

	getchar();
	return 0;
}
