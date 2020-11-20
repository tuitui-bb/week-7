#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
	int main()
{
	cv::Mat src = imread("D://p3.jpg", 1);
	
	//threshold(dst, dst, 100, 255, THRESH_OTSU);
	float scale = 1;
	double i_minH = 0;
	double i_maxH = 10;
	double i_minS = 43;
	double i_maxS = 255;
	double i_minV = 46;
	double i_maxV = 255;

		
	Mat hsvMat;
	Mat detectMat;

	Size ResImgSiz = Size(src.cols * scale, src.rows * scale);
	Mat dst = Mat(ResImgSiz, src.type());
	resize(src, dst, ResImgSiz, INTER_LINEAR);

	cvtColor(dst, hsvMat, COLOR_BGR2HSV);

	dst.copyTo(detectMat);
	cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV),detectMat);
	threshold(detectMat,detectMat, 100, 255, THRESH_OTSU);
	std::vector<std::vector<Point>> contours;
	findContours(detectMat, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
		for (int i = 0; i < contours.size(); i++) {
				RotatedRect rbox = minAreaRect(contours[i]);
				
				float width = (float)rbox.size.width;
				float height = (float)rbox.size.height;
				float ratio = width / height;
				if (width>100&&height>100) {
					
					cv::Point2f vtx[4];
					rbox.points(vtx);
					for (int i = 0; i < 4; i++) {
						cv::line(src, vtx[i], vtx[i < 3 ? i + 1 : 0], cv::Scalar(0, 0, 255), 2, CV_AA);
					}
				}
			}
		imshow("whie: in the range", detectMat);
		imshow("frame", src);

	waitKey(0);
	return 0;
}