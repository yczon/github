// opencv.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  


using namespace cv;


int main()
{
	// ����һ��ͼƬ����Ϸԭ����  
	Mat img = imread("image.jpg");
	// ����һ����Ϊ "��Ϸԭ��"����  
	cvNamedWindow("��Ϸԭ��");
	// �ڴ�������ʾ��Ϸԭ��  
	imshow("��Ϸԭ��", img);
	// �ȴ�6000 ms�󴰿��Զ��ر�  
	waitKey(6000);
}