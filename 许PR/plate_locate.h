#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace pr{
	enum COLOR
	{
		BLUE=0,
		YELLOW=1,
		WHITE=2
	};
	class CPlateLocate{
	public:
		//CPlateLocate();
		//~CPlateLocate();

		//���ƶ�λ
		int PlateLocate(cv::Mat&, std::vector<cv::Mat>&);
		//settings
		static const int DEFAULT_GAUSSIANBLUR_SIZE = 5;
		static const int SOBEL_SCALE = 1;
		static const int SOBEL_DELTA = 0;
		static const int SOBEL_DDEPTH = -1;
		static const int SOBEL_X_WEIGHT = 1;
		static const int SOBEL_Y_WEIGHT = 0;
		static const int DEFAULT_MORPH_SIZE_WIDTH = 17;  // 17
		static const int DEFAULT_MORPH_SIZE_HEIGHT = 3;  // 3
		static const int DEFAULT_ANGLE = 60;
		static const int DEFAULT_ERROR_SCALE = 60; //(0-100)

	private:
		//������ɫ��λ 0����ɫ 1����ɫ 2����ɫ
		void PlateColorLocate(cv::Mat&, int, std::vector<cv::Mat>&);
		//����sobel��λ
		void PlateSobelLocate(cv::Mat&, std::vector<cv::Mat>&);
		//��֤���δ�С�Ƿ�Ϊ����
		bool RectVerify(cv::RotatedRect&);
		//ƥ����ɫ 0����ɫ 1����ɫ 2����ɫ
		cv::Mat ColorMatch(cv::Mat&, int, bool);
		//��̬ѧ ��С��Ӿ���
		void MorphPlate(cv::Mat&,cv::Mat&, std::vector<cv::RotatedRect>&);
		//�õ���Խ�����
		bool SafeRect(cv::RotatedRect,cv::Mat&, cv::Rect&);
		//��ת
		void Rotation(cv::Mat&, cv::Mat&,cv::RotatedRect&, double);
		//��ƫб
		void Deflect(cv::Mat&, double);
		//�Ƕ�У��
		void Revise(cv::Mat&, cv::Mat&, std::vector<cv::RotatedRect>&, std::vector<cv::Mat>&);
	};
}