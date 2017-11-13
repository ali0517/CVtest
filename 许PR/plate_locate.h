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

		//车牌定位
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
		//利用颜色定位 0：蓝色 1：黄色 2：白色
		void PlateColorLocate(cv::Mat&, int, std::vector<cv::Mat>&);
		//利用sobel定位
		void PlateSobelLocate(cv::Mat&, std::vector<cv::Mat>&);
		//验证矩形大小是否为车牌
		bool RectVerify(cv::RotatedRect&);
		//匹配颜色 0：蓝色 1：黄色 2：白色
		cv::Mat ColorMatch(cv::Mat&, int, bool);
		//形态学 最小外接矩形
		void MorphPlate(cv::Mat&,cv::Mat&, std::vector<cv::RotatedRect>&);
		//得到不越界矩形
		bool SafeRect(cv::RotatedRect,cv::Mat&, cv::Rect&);
		//旋转
		void Rotation(cv::Mat&, cv::Mat&,cv::RotatedRect&, double);
		//抗偏斜
		void Deflect(cv::Mat&, double);
		//角度校正
		void Revise(cv::Mat&, cv::Mat&, std::vector<cv::RotatedRect>&, std::vector<cv::Mat>&);
	};
}