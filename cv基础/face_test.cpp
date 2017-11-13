#include "opencv2/core/core.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;
string face_cascade_name = "cascade.xml";
//���ļ�������OpenCV��װĿ¼�µ�\sources\data\haarcascades�ڣ���Ҫ����xml�ļ����Ƶ���ǰ����Ŀ¼��
CascadeClassifier face_cascade;
void detectAndDisplay(Mat frame);
int main(int argc, char** argv) {
	Mat image;
	image = imread("E:/���ƺ�/test3/196.jpg", 1);  //��ǰ���̵�imageĿ¼�µ�mm.jpg�ļ���ע��Ŀ¼����
	if (!face_cascade.load(face_cascade_name)) {
		printf("�������������󣬿���δ�ҵ��ļ����������ļ�������Ŀ¼�£�\n");
		return -1;
	}
	detectAndDisplay(image); //����������⺯��
	waitKey(0);
	//��ͣ��ʾһ�¡�
}

void detectAndDisplay(Mat face) {
	std::vector<Rect> faces;
	Mat face_gray;

	cvtColor(face, face_gray, CV_BGR2GRAY);  //rgb����ת��Ϊ�Ҷ�����
	equalizeHist(face_gray, face_gray);   //ֱ��ͼ���⻯

	face_cascade.detectMultiScale(face_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(1, 1));

	//��Բ
	for (int i = 0; i < faces.size(); i++) {
		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		ellipse(face, center, Size(faces[i].width*0.5, faces[i].height*0.6), 0, 0, 360, Scalar(255, 0, 0), 2, 7, 0);
	}

	imshow("����ʶ��", face);
	//imwrite("E:/cvtest/hengs.jpg", face);
}