#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

///////////////// COLOR DETECTION ///////////////////////////////////////////////////////////

Mat imgHSV,mask;
int hmin = 0, smin = 0, vmin = 0;// the quest is how these value came ... and most of times we wou
//would want to use our own values we can do it with the help of trackbars we  can use it with the \
//help of trackbars inbuilt functionality and with trackbars you always use a while loop
int hmax = 179, smax = 255, vmax = 255;
int main()
{
	string path = "Resources/shapes.png";
	Mat img = imread(path);
	//hsv is hue saturation and value
	cvtColor(img, imgHSV, COLOR_BGR2HSV);// we convert  it BGR to HSV(colour space)

	namedWindow("Trackbar", (640, 200));// here we created a window by the name of trackbar and size
	// 640,200

	createTrackbar("Hue Min", "Trackbar", &hmin, 179);// hue min is name of trackbar and we are creat-
	//-ing it inside Trackbar &hmin will give the address, and a maximum value which is 179
	//for hue maximum is 180 and for saturation and value it is 255
	createTrackbar("Hue max", "Trackbar", &hmax, 179);
	createTrackbar("Sat Min", "Trackbar", &smin, 255);
	createTrackbar("Sat max", "Trackbar", &smax, 255);
	createTrackbar("Val Min", "Trackbar", &vmin, 255);
	createTrackbar("Val max", "Trackbar", &vmax, 255);

	while (true)
	{



		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);//We give it imgHSV as input..... then we have lower limit an
		//upper limit we can usually write down the exact color we want but in real life we wont get the
		//same color due to light,diff shadows and reflection ,, mask is an output image

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", mask);
		waitKey(1);
	}


	return 0;
}
