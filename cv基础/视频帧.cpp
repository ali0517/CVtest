#include "opencv2/core/core.hpp"
#include "opencv2//highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{
	VideoCapture lobyy("G:/2017������/D/����2-������Ƶ/�����ζ�-��̬����/office/input.avi");
	if (!lobyy.isOpened())
		cout << "fail to open!" << endl;

	long totalFrameNumber = lobyy.get(CV_CAP_PROP_FRAME_COUNT);//����֡
	cout << "������Ƶ��" << totalFrameNumber << "֡" << endl;
	
	double rate = lobyy.get(CV_CAP_PROP_FPS);//��ȡ֡��
	cout << "֡��Ϊ:" << rate << endl;

	//����ÿһ֡��ͼ��
	Mat frame;
	//��ʾÿһ֡�Ĵ���
	namedWindow("Extracted frame");
	//��֡��ļ��ʱ��:
	int delay = 1000 / rate;
	long frameToStart = 1;
	int frameToStop = 5;

	//����whileѭ����ȡ֡
	//currentFrame����ѭ�����п��ƶ�ȡ��ָ����֡��ѭ�������ı���
	long currentFrame = frameToStart;

	//�˲����ĺ�
	int kernel_size = 3;
	Mat kernel = Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);

	
	bool stop = false;
	while (!stop)
	{
		//��ȡ��һ֡
		if (!lobyy.read(frame))
		{
			cout << "��ȡ��Ƶʧ��" << endl;
			return -1;
		}
		//������˲�����
		imshow("Extracted frame", frame);
		int channals = frame.channels();
		cout << "ͨ����" << channals << endl;
		//filter2D(frame, frame, -1, kernel);
		//imshow("after filter", frame);
		cout << "���ڶ�ȡ��" << currentFrame << "֡" << endl;
		//int channels = currentFrame

		//waitKey(int delay=0)��delay<0ʱ����Զ�ȴ�����delay>0ʱ��ȴ�delay����
		//��ʱ�����ǰû�а�������ʱ������ֵΪ-1�����򷵻ذ���
		int c = waitKey(delay);
		//����ESC���ߵ���ָ���Ľ���֡���˳���ȡ��Ƶ
		if ((char)c == 27 || currentFrame > frameToStop)
		{
			stop = true;
			break;
		}
		//���°������ͣ���ڵ�ǰ֡���ȴ���һ�ΰ���
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

