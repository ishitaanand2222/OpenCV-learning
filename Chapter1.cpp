#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>//image processing
#include<iostream>

using namespace std;
using namespace cv;


////importing images
//int main()
//{
//	string path = "Resources/test.png";
//	Mat img= imread(path);//Mat is datatype matrix for images
//	imshow("Image", img);//
//	waitKey(0);
//
//	return 0;
//}

//importing videos(series of images hence we will loop through all the images
//int main()
//{
//	string path = "Resources/video1.mp4";
//	VideoCapture cap(path);
//	Mat img;
//	while (true)
//	{
//		cap.read(img);
//		imshow("Image", img);//for showing the image
//		waitKey(1);//pause by one millisecond, to slow down increase the millisecnds ,once the 
//		//video is imaged it will give an error because the images now are finished
//	}
//
//	return 0;
//}
// 
// 
// 
//importing webcams
int main()
{
	   // namedWindow("Display window");
		VideoCapture cap(0);//Here we got to write the id number of cameras. if only one camera 
		//write 0 else write the id no.
		/*if (!cap.isOpened()) {

			cout << "cannot open camera";

		}*/

		Mat img;
		while (true)
		{
			cap.read(img);
			imshow("Image", img);
			waitKey(1);
		}
		return 0;


}