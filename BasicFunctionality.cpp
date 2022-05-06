//At a particular time of running code only one file can run at a time .That is main from
//one file can only run ..So to get rid of it there are two ways 1.Cmment down everything 
//in one of the file 2. To exclude that particular file from the project and we can include
//it later


//Basic functionsss


#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/imgcodecs.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main() {

	string path = "Resources/pic9.jpeg";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil,imgErode;
	//after reading we are first converting it into grey scale
	//cvtColor(InputArray,OutputArray,other parameters)
	cvtColor(img, imgGray, COLOR_BGR2GRAY);//cvt color tranforms color from one color space
	//to another in open Cv,RGB is BGR so  COLOR_BGR2GRAY will convert from BGR to grey

	//In c++ destination is written inside the function itself
	//To Add some BLUR 

	GaussianBlur(imgGray, imgBlur, Size(7,7),5,0);//Input,Output,Size of kernel// the values will
	// effect the bluriness.. less values means less bluriness

	//Canny is used for edges detection.Canny uses a little bit of blur thats a common practice
	Canny(imgBlur, imgCanny, 25, 75);// the last parameters are the threshold values
	// to have more edges we can decrease the values

	//Dilate and Errode: Most of times when we detect the edges they are either not completely
// filled or joined or very thin to detect properly, hence we can dilate it which means
	//it will increase the thickness or errode it and it will decrease the thickness

	//In python we can make kernels by numpy,in c++ by getStructuringElement
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));//It creates a kernel which
	// can be used with dilation if we  increase the size more dilation if we dec the size ,
	//less dilation.......We can  only use odd no.

	
	dilate(imgCanny, imgDil ,kernel);
	erode(imgDil, imgErode, kernel);

	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Errode", imgErode);

	waitKey(0);
	return 0;
}
