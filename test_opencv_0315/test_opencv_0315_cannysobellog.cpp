#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat SrcImage = imread("cxy.jpg");

	Mat ProcessImage = SrcImage.clone();

	Mat GaryImage,LogImage, SobelImage_x,SobelImage_y,SobelImage_all,CannyImage;

	cvtColor(ProcessImage, GaryImage, CV_BGR2GRAY);


	Laplacian(GaryImage, LogImage, GaryImage.depth(), 3,1,0,BORDER_DEFAULT);

	Canny(GaryImage, CannyImage, 3, 200, 3);

	Sobel(GaryImage, SobelImage_x, GaryImage.depth(), 1, 0, 3, 1, 1, BORDER_DEFAULT);
	Sobel(GaryImage, SobelImage_y, GaryImage.depth(), 0, 1, 3, 1, 1, BORDER_DEFAULT);
	addWeighted(SobelImage_x, 0.5, SobelImage_y, 0.5, 0, SobelImage_all);
	
	imshow("SobelImage_x", SobelImage_x);
	imshow("SobelImage_y", SobelImage_y);
	imshow("SobelImage_all", SobelImage_all);

	imshow("LogImage", LogImage);
	imshow("GrayImage", GaryImage);
	imshow("CannyImage", CannyImage);
	//
	imwrite("SobelImage_x.jpg", SobelImage_x);
	imwrite("SobelImage_y.jpg", SobelImage_y);
	imwrite("SobelImage_all.jpg", SobelImage_all);

	imwrite("LogImage.jpg", LogImage);
	imwrite("GrayImage.jpg", GaryImage);
	imwrite("CannyImage.jpg", CannyImage);
	//
	waitKey();
	return 0;
}
