#include "opencv2/core/core.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

//��Ҫ����xml�ļ����Ƶ���ǰ����Ŀ¼��
string pr_cascade_name = "cascade.xml";
CascadeClassifier pr_cascade;

void detectAndDisplay(Mat frame);
void deal_files();

int main(int argc, char** argv) {
	//xml�ļ��Ƿ����
	if (!pr_cascade.load(pr_cascade_name)) {
		printf("�������������󣬿���δ�ҵ��ļ����������ļ�������Ŀ¼�£�\n");
		return -1;
	}
	
	//deal_files();
}

void detectAndDisplay(Mat face) {
	std::vector<Rect> faces;
	Mat face_gray;
	//Ԥ����
	cvtColor(face, face_gray, CV_BGR2GRAY);  //rgb����ת��Ϊ�Ҷ�����
	equalizeHist(face_gray, face_gray);   //ֱ��ͼ���⻯
	//���
	pr_cascade.detectMultiScale(face_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(1, 1));
	//������
	for (int i = 0; i < faces.size(); i++) {
		Scalar color = Scalar(0, 0, 255);
		rectangle(face, cvPoint(faces[i].x, faces[i].y), cvPoint(faces[i].x + faces[i].width, faces[i].y + faces[i].height), color, 2, LINE_8);
	}
		//��ȡ
		//roi_img = plate(Range(plates[i].x, plates[i].x + plates[i].height), Range(plates[i].y, plates[i].y + plates[i].width));
		//roi_img = plate(Range(plates[i].x- plates[i].height*0.5, plates[i].x + plates[i].height*1.3), Range(plates[i].y - plates[i].width*0.2, plates[i].y + plates[i].width*1.2));
		//warpAffine(srcImage, dstImage, MArray, Size(srcImage.size()), 1, 0, Scalar(0));
}

void deal_files() {
	char filename1[256];
	char filename2[256];
	//��ȡ�ļ����ͼ��
	for (int i = 1; i <= 237; i++) {
		//��ȡ    %s�ַ���"E:/���ƺ�/test3"    \\�µ�   %d ��i�� jpg
		sprintf(filename1, "%s\\%d.jpg", "E:/���ƺ�/test3", i);
		Mat img = imread(filename1);
		//���
		detectAndDisplay(img);
		//����
		sprintf(filename2, "%s\\%d.jpg", "E:/���ƺ�/test5", i);
		imwrite(filename2, img);
	}
}