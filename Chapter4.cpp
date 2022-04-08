#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>

using namespace std;
using namespace cv;

////////////////////// Draw  Shapes and Text ////////////////

int main()
	{
		//Blank image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));//(size,size,type 8 here means 8 bits i.e values from 0-255 U 
		// means unsigend and C3 means 3  color channels(BGR),Scalar stands for the color you want
		// to have Scalar(255,0,0) is for having blue color; for white(255,255,255)

	circle(img, Point(256, 256), 155, Scalar(0, 69, 255),FILLED);// in this we need to define the origin 
	//points with the help of datatype point(x,y) this will give the origin point ie center 512/2=
	//256.... 155 is size of circle and scalar will give color.To  increase thickness 
	//circle(img, Point(256, 256), 155, Scalar(0, 69, 255),10); write 10 if we want filled
	//circle(img, Point(256, 256), 155, Scalar(0, 69, 255),FILLED);

	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);//Here the 
	//we give two points i.e top left corner  and bottom right corner of rectangle

	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	putText(img, "ISHITA ANAND", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);
    // here 0.75 gives thickness ; 2 gives thickness
	imshow("Image", img);

	waitKey(0);
			return 0;
	}
