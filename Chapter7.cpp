#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

//////////////////////////// Shapes/countour detection //////////////////////////////
// We need to first preprocess our image the basic idea is we finding the edges and then we
// can easily detect the shapes
Mat imgGray, imgBlur, imgCanny,imgDil;

void getContours(Mat imgDil, Mat img)//imgDil we want to find the contours on and img we want to draw on 
{
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;//4i means 4 integer values;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	/*drawContours(img, contours, -1, Scalar(255, 0, 255), 2);*/// to draw contours img is the image in
	//which we want to draw on ,we can have also the contour no. which we want to draw but in this 
	//case we want to draw all hence write -1 and Scalar for clr and 2 for thickness


	//we want to find the area of countour and we want to filter out

	vector<vector<Point>>conPoly(contours.size());
	vector<Rect>boundRect(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << "\n";


		
		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			// we find the no. of corners points;
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			
			cout << conPoly[i].size() << "\n";
			boundRect[i] = boundingRect(conPoly[i]);// we use to find the bounding rectangle
			
			//boundRect[i].tl() gives top left coordinate point and boundRect[i].br() gives bottom
			//right coordinates point

			int objCor = (int)conPoly[i].size();
			if (objCor == 3) { objectType = "Tri"; }
			if (objCor == 4) {
				
				float aspRatio = (float)boundRect[i].width /(float) boundRect[i].height;
				cout << aspRatio << '\n';
				if (aspRatio > 0.95 && aspRatio < 1.05)
					objectType = "Square";
				else
				objectType = "Rect";
			}
			if (objCor > 4) { objectType = "Cir"; }

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0),5);
			putText(img, objectType,{boundRect[i].x,boundRect[i].y-5}, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 1);


		}
	}


}
int main()
{

	string path = "Resources/shapes.png";
	Mat img = imread(path);


	//STEP1::PREPROCESSING OF THE IMAGE
	//from chapter 2
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);// with dilated  image our detection is better as compared
	// to canny

	getContours(imgDil,img);

	imshow("Image", img);
	/*imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("'Image Canny", imgCanny);
	imshow("Image Dilate", imgDil);*/

	waitKey(0);



	//cout << "Heyy\n";



	return 0;
}