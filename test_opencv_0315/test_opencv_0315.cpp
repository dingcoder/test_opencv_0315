#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
using namespace cv;
using namespace std;

static void on_ContrastAndBright(int, void *);

static void ShowHelpText();

int g_nContrasValue;
int g_nBrightValue;
Mat g_srcImage, g_dstImage;

int main()
{
	g_srcImage = imread("a.jpg");
	if (!g_srcImage.data)
	{
		cout << "input image error" << endl;
		return false;
	}

	g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());

	g_nBrightValue = 80;
	g_nContrasValue = 80;

	namedWindow("window one", 1);

	createTrackbar("contrasvalue", "window one", &g_nContrasValue, 300, on_ContrastAndBright);
	createTrackbar("brightvalue", "window one", &g_nContrasValue, 300, on_ContrastAndBright);


	on_ContrastAndBright(g_nContrasValue, 0);
	on_ContrastAndBright(g_nBrightValue, 0);

	while (char(waitKey(1)) != 'q')
	{

	}
	return 0;
}

static void on_ContrastAndBright(int, void *)
{
	namedWindow("window one", 1);

	for (int y = 0;y < g_srcImage.rows;y++)
	{
		for (int x = 0;x < g_srcImage.cols;x++)
		{
			for (int c = 0;c < 3;c++)
			{
				g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrasValue*0.01)*(g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);

			}
		}
	}

	imshow("window one", g_srcImage);
	imshow("window two", g_dstImage);
}