#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

//÷∏’ÎªÒ»°œÒÀÿ  *p  = prt<>(i)  p[j]= °£°£°£°£  
// src.at<>(i,j) = pixel

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("E:/cvtest/img/he2.jpg");
	if (!src.data) {
		printf("could find the file!\n");
		return -1;
	}
	//namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("input", src);
	
	Mat aaa(src.size(), src.type());
	Mat bbb(300, 300, CV_8UC1);
	Mat ccc(300, 300, CV_8UC3);
	Mat ddd(300, 300, CV_8UC3);
	src.copyTo(dst);

	for (int i = 0; i < bbb.cols; i++) {
		uchar *p = bbb.ptr<uchar>(i);
		for (int j = 0; j < bbb.rows; j++) {
			p[j] = 2*(i+j) % 255;
		}
	}
	imshow("bbb", bbb);

	for (int i = 0; i < ccc.cols; i++) {
		Vec3b *p = ccc.ptr<Vec3b>(i);
		for (int j = 0; j < ccc.rows; j++) {
			p[j][0] = 2*j % 255;
			p[j][1] = (i+j) % 255;
			p[j][2] = 3*j % 255;
		}
	}
	imshow("ccc", ccc);

	for (int i = 0; i < ccc.cols; i++) {
		for (int j = 0; j < ccc.rows; j++) {
			Vec3b pixel;
			pixel[0] = 0;
			pixel[1] = 3 * (i+j) % 255;
			pixel[2] = 5 * i % 255;
			ddd.at<Vec3b>(i,j) = pixel;
		}
	}

	imshow("ddd", ddd);


	waitKey(0);
	return 0;
}