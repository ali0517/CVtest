#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

//瞎试 trackbar 

using namespace cv;
using namespace std;


int value = 20;
int max_value = 100;
void asd(int, void*);
Mat src, dst ,dst2;

int main(int argc, char** argv) {
	
	src = imread("E:/cvtest/img/he2.jpg");
	if (!src.data) {
		printf("could find the file!\n");
		return -1;
	}
	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("input", src);
	createTrackbar("aaa", "output", &value, max_value,asd );
	asd(0, 0);

	waitKey(0);
	return 0;
}

void asd(int, void*) {
	blur(src, dst, Size(3, 3), Point(-1, -1),BORDER_DEFAULT);
	Canny(dst, dst2, value, value * 2, 3, false);
	imshow("output", dst2);
}