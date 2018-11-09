#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>

#include <iostream>
#include <cstdio>

using namespace cv;
using namespace std;
/*
�����ǲ߸g���k��R ���OpenCV
�� 1���@���A������������
*/
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main( int argc, char** argv )
{
	float trainingData[8][3] = { {6, 180, 12}, {5.92, 190, 11}, {5.58, 170, 12}, {5.92, 165, 10},
								{5, 100, 6}, {5.5, 150, 8},{5.42, 130, 7}, {5.75, 150, 9}};/*����(�^��),�魫(�S),�}�x(�^�T)*/
	Mat trainingDataMat(8, 3, CV_32FC1, trainingData);

	float responses[8] = {'M', 'M', 'M', 'M', 'F', 'F', 'F', 'F'};/*M:�k F:�k*/
	Mat responsesMat(8, 1, CV_32FC1, responses);

	CvNormalBayesClassifier nbc;
	nbc.train(trainingDataMat, responsesMat);

	float myData[3] = {6, 130, 8};
	Mat myDataMat(1, 3, CV_32FC1, myData);
	float r = nbc.predict( myDataMat );

	cout<<endl<<"result:  "<<(char)r<<endl;

    Pause();
	return 0;

 }
