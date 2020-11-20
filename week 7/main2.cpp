//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace cv;
//int main() {
//	cv::Mat src = imread("D://p2.jpg", 0);
//	cv::Mat dst;
//	//Canny(src, dst, 100, 155, 3, false);
//	threshold(src, dst, 100, 125, THRESH_OTSU);
//	std::vector<std::vector<Point>> contours;
//	findContours(dst, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
//	for (int i = 0; i < contours.size(); i++) {
//		RotatedRect rbox = minAreaRect(contours[i]);
//		float width = (float)rbox.size.width;
//		float height = (float)rbox.size.height;
//		float ratio = width / height;
//		if (ratio <1.1&&ratio >0.88) {
//		drawContours(src, contours, i, Scalar(255, 255, 0), 1, 8);
//		cv::Point2f vtx[4];
//		rbox.points(vtx);
//		for (int i = 0; i < 4; i++) {
//			cv::line(src, vtx[i],vtx[i <3 ? i + 1 : 0], cv::Scalar(0, 0, 255), 2, CV_AA);
//	}
//		}
//	}
//	imshow("src", src);
//	imshow("dst", dst);
//	waitKey(0);
//	return 0;
//}