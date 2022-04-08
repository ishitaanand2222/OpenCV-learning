#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>//used to work with hard cascade files
#include<iostream>

using namespace std;
using namespace cv;

///////////////////////// Face detection /////////////////////////////

int main()
{
	string path = "Resources/test.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;// we will load our CascadeClassifier
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	//this statement is to check if the image is loaded or not
	if (faceCascade.empty()) { cout << "XML file not loaded\n"; }

	vector<Rect>faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);//detects objects of different sizes in the input
	// detected objects from the images are returned as a list of rectangle 1.1 is scale factor(
	// how much image size is reduced at each image Scale
	//10 is minimum neighbours it specifies how many  neighbours each candidate rectangle should have
	//to retain it

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img,faces[i].tl(), faces[i].br(), Scalar(255,0,255),3);
	}

	imshow("Image", img);
	waitKey(0);




	return 0;
}