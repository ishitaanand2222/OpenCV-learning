#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

/////////////////////////////// Project 1 : Virtual Painter //////////////////////////////////
//1) We would require webCam
//We will first detect the colors with hsv color space followed by contour detection and we take
//take their x and y position to draw circle


Mat img;
vector<vector<int>>newPoints;//it will have x and y and color value
vector<vector<int>>myColors{{102,71,80,134,170,166}//purple
,{95,127,104,113,255,205}//,//Blue
	//{9,151,134,23,255,177}//Mustard
};

vector<Scalar>myColorValues{ {255,0,255},//Purple
	                         {200,0,0}//,//blue
	                         //{ 255, 219, 88}//mustard
};




//array of colors consisting of min and max values i,e will have multiple
//mask if we have 4 vector means it will detect 4 colors if we have 2 vector hence it will detect 2
//color we are not hard coding it here


//from chapter 7
Point getContours(Mat image) 
{
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;

	findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	vector<vector<Point>>conPoly(contours.size());
	vector<Rect>boundRect(contours.size());

	Point myPoint(0, 0);
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);//area is needed for filteration
		cout << area << "\n";


		
		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);


			cout << conPoly[i].size() << "\n";
			boundRect[i] = boundingRect(conPoly[i]);
			myPoint.x = boundRect[i].x + boundRect[i].width / 2;//divide by 2 becuz we want 
			//to draw from center not from edge
			myPoint.y = boundRect[i].y;

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			////bounding box
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 6), 5);
			
		}
	}

	return myPoint;


}







vector<vector<int>> findColor(Mat img)
{
	Mat imgHSV;
	
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	for (int i = 0; i < myColors.size(); i++)
	{
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		//imshow(to_string(i), mask);
		Point myPoint = getContours(mask);
		circle(img, myPoint, 10, Scalar(255, 0, 255), FILLED);
		if (myPoint.x != 0) {
			newPoints.push_back({ myPoint.x, myPoint.y, i });// i is the color
		}

	}
	return newPoints;

}
//102, 71, 80, 134, 170, 166

void drawOnCanvas(vector<vector<int>>newPoints, vector<Scalar>myColorValues)
{
	for (int i = 0; i < newPoints.size(); i++)
	{
		circle(img, Point(newPoints[i][0],newPoints[i][1]), 10, myColorValues[newPoints[i][2]], FILLED);
	}
}

int main()
{
	VideoCapture cap(0);//Here we write the id no. of camera since we have only one we write 0;

	//To check if cap is openend or not i.e our webcam
	/*if (!cap.isOpened())
		cout << "WEB cam can't be opened\n";
	*/

	while (true)
	{
		cap.read(img);
		newPoints = findColor(img); //function to find the color
		drawOnCanvas(newPoints,myColorValues);
		imshow("Image", img);
		waitKey(1);
	}






	return 0;
}