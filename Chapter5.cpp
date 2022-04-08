#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>

using namespace std;
using namespace cv;


//////////////// Warp Images:Say we have an image and we take that image as if we took
// from birds eye view   /////////////////////////////

float w = 250, h = 350;
Mat matrix,imgWarp;
int main()
{
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };// we can these pixel values 
// if we put them on paint (at the bottom of the screen we can have coordinates
	//Point2f is floating point 4 is the size of the matrix
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);// to tranform 
	warpPerspective(img, imgWarp, matrix, Point(w, h));// Point(w, h) will give size

	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);

	waitKey(0);
	return 0;
}