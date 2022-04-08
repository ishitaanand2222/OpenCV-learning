#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	string path = "Resources/pic9.jpeg";
	Mat img = imread(path);
	Mat imgResize,imgCrop;

	//to evaluate the size of image
	//cout << img.size() << endl;


	//resize(img, imgResize, Size(640,480));
	//We can also scale our images
	resize(img, imgResize, Size(), 0.5, 0.5);// reduces images by 50%

	//Cropping 

	Rect roi(100, 100, 300, 250);//Rect is a datatype and roi is region of interest in which
// we give values of x,y,width,height; x,y are the values of coordinates from there we 
	// will go 300 width and 250 height

	imgCrop = img(roi);
	
	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Crop", imgCrop);

	waitKey(0);

	return 0;
}