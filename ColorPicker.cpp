#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//////////////Color Picker ::: Same code as that of chap 6 except we now use a webacam////////////

int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;
VideoCapture cap(0);
Mat img,imgHSV,mask;
int main()
{
	namedWindow("Trackbars", (640, 200));//Create a window by name of trackbar and size (640,200))

	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 255);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);


	while (true)
	{
		cap.read(img);

		cvtColor(img, imgHSV, COLOR_BGR2HSV);

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);

        
		cout << hmin << "," << smin << "," << vmin << "," << hmax << "," << smax << "," << vmax << "\n";


		imshow("Image", img);
		imshow("Mask", mask);

		waitKey(1);
	}


	return 0;
}