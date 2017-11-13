#include "opencv2/core/core.hpp"
#include "opencv2//highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{
	VideoCapture lobyy("G:/2017年试题/D/附件2-典型视频/不带晃动-静态背景/office/input.avi");
	if (!lobyy.isOpened())
		cout << "fail to open!" << endl;

	long totalFrameNumber = lobyy.get(CV_CAP_PROP_FRAME_COUNT);//多少帧
	cout << "整个视频共" << totalFrameNumber << "帧" << endl;
	
	double rate = lobyy.get(CV_CAP_PROP_FPS);//获取帧率
	cout << "帧率为:" << rate << endl;

	//承载每一帧的图像
	Mat frame;
	//显示每一帧的窗口
	namedWindow("Extracted frame");
	//两帧间的间隔时间:
	int delay = 1000 / rate;
	long frameToStart = 1;
	int frameToStop = 5;

	//利用while循环读取帧
	//currentFrame是在循环体中控制读取到指定的帧后循环结束的变量
	long currentFrame = frameToStart;

	//滤波器的核
	int kernel_size = 3;
	Mat kernel = Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);

	
	bool stop = false;
	while (!stop)
	{
		//读取下一帧
		if (!lobyy.read(frame))
		{
			cout << "读取视频失败" << endl;
			return -1;
		}
		//这里加滤波程序
		imshow("Extracted frame", frame);
		int channals = frame.channels();
		cout << "通道数" << channals << endl;
		//filter2D(frame, frame, -1, kernel);
		//imshow("after filter", frame);
		cout << "正在读取第" << currentFrame << "帧" << endl;
		//int channels = currentFrame

		//waitKey(int delay=0)当delay<0时会永远等待；当delay>0时会等待delay毫秒
		//当时间结束前没有按键按下时，返回值为-1；否则返回按键
		int c = waitKey(delay);
		//按下ESC或者到达指定的结束帧后退出读取视频
		if ((char)c == 27 || currentFrame > frameToStop)
		{
			stop = true;
			break;
		}
		//按下按键后会停留在当前帧，等待下一次按键
		if (c >= 0)
		{
			waitKey(0);
		}
		currentFrame++;
	}
	lobyy.release();
	waitKey(0);
	return 0;
}

