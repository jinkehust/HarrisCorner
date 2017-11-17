#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include"opencv2/imgproc/imgproc.hpp"  
#include <iostream>  
using namespace std;
using namespace cv;

int main()
{
	Mat Image = imread("test1.jpg");
	Mat HarrisCorner, GrayImage,GaussImage;
	cvtColor(Image, GrayImage, CV_RGB2GRAY);
	GaussianBlur(GrayImage, GaussImage, Size(3, 3), 0, 0);
	cornerHarris(GaussImage, HarrisCorner, 2, 3, 0.01);
	
	Mat norm_Harris, norm_scale;
	normalize(HarrisCorner, norm_Harris, 0, 255, NORM_MINMAX, CV_32FC1, Mat());

	for (int j = 0; j < norm_Harris.rows; j++)
	{
		for (int i = 0; i < norm_Harris.cols; i++)
		{
			if ((int)norm_Harris.at<float>(j, i) > 200)   //thresh
			{
				circle(Image, Point(i, j), 5, Scalar(255, 0, 0), -1, 8, 0);
			}
		}
	}
	imshow("角点检测", Image);
	
	waitKey();
	return 0;
}
